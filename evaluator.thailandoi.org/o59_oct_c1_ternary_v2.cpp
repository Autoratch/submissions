#include <bits/stdc++.h>
using namespace std;

const long long N = 101;
const long long MOD = 1e9 + 7;

long long n;
long long a[N],b[N];
long long dp[N][N][N];
bool visited[N][N][N];
set<long long> st;

long long solve(long long ax,long long ay,long long bx,long long by)
{
    if(ay-ax!=by-bx) return 0;
    if(ax>ay) return 0;
    if(ax==ay) return a[ax]==b[bx];
    long long sz = ay-ax+1;
    if(visited[ax][bx][sz]) return dp[ax][bx][sz];
    visited[ax][bx][sz] = true;
    st.clear();
    for(long long i = ax;i <= ay;i++) st.insert(a[i]);
    bool ok = true;
    for(long long i = bx;i <= by;i++) if(st.find(b[i])==st.end()) ok = false;
    if(!ok) return dp[ax][bx][sz] = 0;
    long long rt;
    for(long long i = bx;i <= by;i++) if(b[i]==a[ax]) rt = i;
    long long res = 1,insz = rt-bx;
    if(insz) res = (res*solve(ax+1,ax+insz,bx,bx+insz-1))%MOD;
    long long bck = 0;
    bool in = false;
    long long sta = ax+insz+1,stb = bx+insz+1;
    for(long long i = sta,j = stb;i < ay;i++,j++)
    {
        bck = (bck+solve(sta,i,stb,j)*solve(i+1,ay,j+1,by))%MOD;
        in = true;
    }
    if(sta<=ay) bck = (bck+solve(sta,ay,stb,by)*2LL)%MOD;
    if(bck) res = (res*bck)%MOD;
    return dp[ax][bx][sz] = res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 0;i < n;i++) cin >> a[i];
    for(long long i = 0;i < n;i++) cin >> b[i];

    cout << solve(0,n-1,0,n-1);
}
