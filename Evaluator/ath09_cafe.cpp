#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int t,n;
vector<vector<int> > adj;
int dp[N][3]; // 0-not use   1-use u but not p   2-use u and p

void dfs(int u,int p)
{
    dp[u][0] = 0;
    dp[u][1] = dp[u][2] = 1;
    int sum = 0,mxd = 0;
    for(int v : adj[u])
    {
        if(v==p) continue;
        dfs(v,u);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        sum+=dp[v][0];
        mxd = max(mxd,dp[v][2]-dp[v][0]);
    }
    dp[u][1]+=sum+mxd;
    dp[u][2]+=sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        adj.clear();
        adj.resize(n+1);
        for(int i = 0;i < n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,0);
        cout << max(dp[1][0],dp[1][1]) << '\n';
    }
}
