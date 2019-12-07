#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int n;
long long res[N];
vector<int> adj[N];
long long dp[N][4],mx[N][4];
long long ans;

void dfs(int u,int p)
{
    dp[u][0] = mx[u][0] = res[u];
    for(int v : adj[u]) if(v!=p)
    {
        dfs(v,u);
        if(dp[v][0]>dp[u][0]) dp[u][0] = mx[u][0] = dp[v][0];
        for(int j = 1;j <= 3;j++)
        {
            if(dp[v][j]>dp[u][j]) dp[u][j] = dp[v][j],mx[u][j] = mx[v][j];
            if(mx[v][j-1]>res[u] and dp[v][j-1]+res[u]>dp[u][j]) dp[u][j] = dp[v][j-1]+res[u],mx[u][j] = res[u];
        }
    }
    ans = max(ans,dp[u][3]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> res[i];
    for(int i = 1;i <= n;i++) adj[i].clear();
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout << ans;
}
