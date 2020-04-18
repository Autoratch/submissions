#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int t,n;
vector<int> adj[N];
int dp[N][3];

void dfs(int u,int p)
{
    dp[u][1] = dp[u][2] = 1;
    for(int v : adj[u]) if(v!=p) 
    {
        dfs(v,u);
        dp[u][0]+=max(dp[v][0],max(dp[v][1],dp[v][2]));
        dp[u][1]+=dp[v][0];
        dp[u][2]+=dp[v][1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) adj[i].resize(0),dp[i][0] = dp[i][1] = dp[i][2] = 0;
        for(int i = 0;i < n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,0);
        cout << max(dp[1][0],max(dp[1][1],dp[1][2])) << '\n';
    }
}
