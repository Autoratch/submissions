#include <bits/stdc++.h>
using namespace std;

const int N = 1501;

int m,n,k,ans;
int o[N][N],a[N][N],s[4][N][N];

pair<int,int> help(int idx,int x,int y)
{
    if(idx>4) swap(x,y),idx-=4;
    if(idx==0) return {x,y};
    else if(idx==1) return {m+1-x,y};
    else if(idx==2) return {x,n+1-y};
    else return {m+1-x,n+1-y};
}

void solve(int idx,int m,int n)
{
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        auto [x,y] = help(idx,i,j);
        a[i][j] = o[x][y]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
    for(int t = 1;t <= 3;t++)
    {
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) if(i>=k and j>=k)
        {
            s[t][i][j] = max(s[t-1][i-k][j],s[t-1][m][j-k])+a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
            s[t][i][j] = max(s[t][i][j],max(s[t][i-1][j],s[t][i][j-1]));
            ans = max(ans,s[t][i][j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> o[i][j];
    for(int i = 0;i < 4;i++) solve(i,m,n);
    for(int i = 5;i < 8;i++) solve(i,n,m);
    cout << ans;
}
