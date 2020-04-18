#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const long long MOD = 1e9 + 7;

int n;
int a[N],b[N];
long long dp[N][N][N];
bool visited[N][N][N];
set<int> s;

bool no(int al,int ar,int bl,int br)
{
    s.clear();
    for(int i = al;i <= ar;i++) s.insert(a[i]);
    for(int i = bl;i <= br;i++) if(s.find(b[i])==s.end()) return true;
    return false;
}

long long solve(int al,int bl,int sz)
{
    int ar = al+sz-1,br = bl+sz-1;
    if(al>ar or bl>br) return 1;
    if(visited[al][bl][sz]) return dp[al][bl][sz];
    visited[al][bl][sz] = true;
    if(no(al,ar,bl,br)) return 0;
    if(al==ar){ dp[al][bl][sz] = 1; return 1; }
    int idb,ll;
    for(int i = bl;i <= br;i++) if(b[i]==a[al]){ idb = i; ll = i-bl;  break; }
    long long lft = solve(al+1,bl,ll),rgt = 0;
    int lr = ar-al-ll;
    for(int i = 1;i < lr;i++)
    {
        // al+ll+1 --> ar , bl+ll+1 --> br
        long long r1 = solve(al+ll+1,bl+ll+1,i)%MOD;
        long long r2 = solve(al+ll+1+i,bl+ll+1+i,lr-i)%MOD;
        rgt = (rgt+(r1*r2)%MOD)%MOD;
    }
    rgt = (rgt+solve(al+ll+1,bl+ll+1,lr)*2%MOD)%MOD;
    long long res;
    if(ll and lr) res = (rgt*lft)%MOD;
    else if(ll) res = lft;
    else res = rgt;
    dp[al][bl][sz] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    cout << solve(0,0,n);
}
