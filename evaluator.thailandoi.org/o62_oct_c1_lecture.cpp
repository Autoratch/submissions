#include <bits/stdc++.h>
using namespace std;

const long long N = 301;
const long long C = 1e5;

long long c,n,m;
long long res[C];
long long dist[N][N];
long long pth[C];

bool solve(long long x)
{
    long long used = 0,dl = res[0];
    for(long long i = 1LL;i < c;i++)
    {
        used+=dist[pth[i-1LL]][pth[i]]*x;
        dl+=res[i];
        used = max(used,dl-res[i]);
        if(used>dl) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> c >> n >> m;
    for(long long i = 0;i < c;i++) cin >> pth[i];
    for(long long i = 0;i < c;i++) cin >> res[i];
    for(long long i = 1LL;i <= n;i++) for(long long j = 1LL;j <= n;j++) dist[i][j] = LLONG_MAX;
    for(long long i = 0;i < m;i++)
    {
        long long a,b,d;
        cin >> a >> b >> d;
        dist[a][b] = dist[b][a] = d;
    }
    for(long long k = 1LL;k <= n;k++) for(long long i = 1LL;i <= n;i++) for(long long j = 1LL;j <= n;j++) 
        if(dist[i][k]!=LLONG_MAX and dist[k][j]!=LLONG_MAX) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    for(long long i = 1LL;i <= n;i++) dist[i][i] = 0;
    long long l = 1LL,r = 1000000000LL;
    while(l<r)
    {
        long long m = (l+r+1LL)/2LL;
        bool ok = solve(m);
        if(ok) l = m;
        else r = m-1LL;
    }
    cout << l;
}
