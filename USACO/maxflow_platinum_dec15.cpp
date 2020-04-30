#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;
const int K = 19;

int n,m,ans;
vector<int> adj[N];
int dp[K][N],lv[N],res[N];

void dfs(int u,int p)
{
    dp[0][u] = p,lv[u] = lv[p]+1;
    for(int v : adj[u]) if(v!=p) dfs(v,u);
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

void sum(int u,int p)
{
    for(int v : adj[u]) if(v!=p) sum(v,u),res[u]+=res[v];
    ans = max(ans,res[u]);
}

int main()
{
    freopen("maxflow.in","r",stdin);
    freopen("maxflow.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        int l = lca(a,b);
        res[a]++,res[b]++,res[l]--,res[dp[0][l]]--;
    }
    sum(1,0);
    cout << ans;
}
