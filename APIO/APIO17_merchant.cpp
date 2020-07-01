#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int K = 1001;

int n,m,k;
int b[N][K],s[N][K];
int diso[N][N],sell[N][N];
long long dist[N][N];

bool solve(long long x)
{
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) dist[i][j] = (long long)diso[i][j]*x-(long long)sell[i][j];
    for(int i = 1;i <= n;i++) dist[i][i] = INT_MAX;
    for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) 
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    for(int i = 1;i <= n;i++) if(dist[i][i]<=0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= k;j++) cin >> b[i][j] >> s[i][j];
    for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++) diso[i][j] = diso[j][i] = INT_MAX;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        diso[a][b] = min(diso[a][b],d);
    }
    for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) 
        if(diso[i][k]!=INT_MAX and diso[k][j]!=INT_MAX) diso[i][j] = min(diso[i][j],diso[i][k]+diso[k][j]);
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) for(int l = 1;l <= k;l++) 
        if(s[j][l]>0 and b[i][l]>0) sell[i][j] = max(sell[i][j],s[j][l]-b[i][l]);
    long long l = 0,r = 1e9;
    while(l<r)
    {
        long long m = (l+r+1LL)/2LL;
        if(solve(m)) l = m;
        else r = m-1;
    }
    cout << l;
}
