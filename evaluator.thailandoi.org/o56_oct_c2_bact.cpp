#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int m,n,k;
int a[N][N],am[900],tmp[900];
int dp[N][N][N][N],visited[N][N][N][N];

int solve(int ax,int ay,int bx,int by)
{
    if(visited[ax][ay][bx][by]) return dp[ax][ay][bx][by];
    visited[ax][ay][bx][by] = true;
    int res = 0;
    if(ax==ay or bx==by)
    {
        for(int i = 1;i <= k;i++) tmp[i] = 0;
        for(int i = ax;i <= ay;i++) for(int j = bx;j <= by;j++) tmp[a[i][j]]++;
        for(int i = 1;i <= k;i++) if(tmp[i]==am[i] and am[i]) res++;
    }
    else
    {
        res = max(res,solve(ax,ax,bx,by)+solve(ax+1,ay,bx,by));
        res = max(res,solve(ay,ay,bx,by)+solve(ax,ay-1,bx,by));
        res = max(res,solve(ax,ay,bx,bx)+solve(ax,ay,bx+1,by));
        res = max(res,solve(ax,ay,by,by)+solve(ax,ay,bx,by-1));
    }
    return dp[ax][ay][bx][by] = res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++){ cin >> a[i][j]; am[a[i][j]]++; }
    
    cout << solve(0,m-1,0,n-1);
}
