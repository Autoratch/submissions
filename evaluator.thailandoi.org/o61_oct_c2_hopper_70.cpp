#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;

int n,k;
vector<pair<int,int> > adj[N];
int a[N];
int dp[N][N+1];
int ans = INT_MAX;
bool visited[N];

void dfs(int u,int p,int w)
{   
    if(!visited[u]) for(int i = 0;i < adj[u].size();i++) dfs(adj[u][i].second,u,adj[u][i].first);
    visited[u] = true;
    ans = min(ans,dp[u][k]);
    if(p!=-1) for(int i = 0;i < k;i++) dp[p][i+1] = min(dp[p][i+1],max(dp[u][i],w));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        for(int j = i+1;j != i;j = (j+1)%n)
        {
            if(a[j]>a[i]) adj[i].push_back({((j-i)+n)%n,j});
        }
    }
/*
    int l = 0,r = n;

    while(l<r)
    {
        int m = (l+r)/2;
         
    }
*/
    for(int i = 0;i < n;i++) for(int j = 1;j <= k;j++) dp[i][j] = INT_MAX;

    for(int i = 0;i < n;i++) if(!visited[i]) dfs(i,-1,0);

    cout << ans;
}
