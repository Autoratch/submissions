#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 20;

int n,m;
vector<int> adj[N];
int sz[N],pa[N];
bool blocked[N];
int res[N],dp[K][N],lv[N];

void dfs(int u,int p)
{
    sz[u] = 1;
    for(int v : adj[u]) if(v!=p and !blocked[v]) dfs(v,u),sz[u]+=sz[v];
}
 
void build(int u,int cp)
{
    dfs(u,0);
    int c = u,prev = 0;
    while(true)
    {
        int mx = -1,id;
        for(int v : adj[c]) if(!blocked[v] and v!=prev) if(sz[v]>mx) mx = sz[v],id = v;
        if(mx*2>sz[u]) prev = c,c = id;
        else break;
    }
    pa[c] = cp;
    blocked[c] = true;
    for(int v : adj[c]) if(!blocked[v]) build(v,c);
}

void dfslca(int u,int p)
{
    lv[u] = lv[p]+1,dp[0][u] = p;
    for(int v : adj[u]) if(v!=p) dfslca(v,u);
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int dist(int a,int b){ int l = lca(a,b); return lv[a]-lv[l]+lv[b]-lv[l]; }

void update(int x){ for(int u = x;u;u = pa[u]) res[u] = min(res[u],dist(u,x)); }

int query(int x){ int ret = INT_MAX; for(int u = x;u;u = pa[u]) if(res[u]!=INT_MAX) ret = min(ret,dist(u,x)+res[u]); return ret; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfslca(1,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    build(1,0);
    for(int i = 1;i <= n;i++) res[i] = INT_MAX;
    update(1);
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        if(x==1) update(y);
        else cout << query(y) << '\n';
    }
}
