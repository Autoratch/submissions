#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
vector<int> adj[N];
int s[N],dp[N][2];

void solve(int u,int p)
{
    dp[u][1] = s[u];
    for(int v : adj[u]) if(v!=p)
    {
        solve(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][1],dp[v][0]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> s[i];

    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve(0,0);

    cout << max(dp[0][0],dp[0][1]);
}
