#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int MOD = 33331;

int n,m,q;
vector<pair<int,int> > adj[N];
int pa[N];
vector<tuple<int,int,int> > ed;
int dp[20][N],lv[N],dist[N];
int val[10000001];

int root(int x){ if(pa[x]==x) return x; else return pa[x] = root(pa[x]); }

void dfs(int u,int p,int l)
{
    lv[u] = l,dp[0][u] = p;
    for(auto [d,v] : adj[u]) if(p!=v) dist[v] = (dist[u]+val[d])%MOD,dfs(v,u,l+1);
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = 19;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = 19;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        ed.push_back({d,a,b});
    }
    sort(ed.begin(),ed.end());
    for(int i = 1;i <= n;i++) pa[i] = i;
    for(auto [d,a,b] : ed)
    {
        if(root(a)==root(b)) continue;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
        pa[root(a)] = root(b);
    }
    val[0] = 1;
    for(int i = 1;i <= 1e7;i++) val[i] = (val[i-1]*2)%MOD;
    dfs(1,0,1);
    for(int i = 1;i < 20;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int l = lca(a,b);
        cout << ((dist[a]-dist[l]+dist[b]-dist[l])%MOD+MOD)%MOD << '\n';
    }
}
