#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 17;

int n,m;
set<int> adj[N];
vector<tuple<int,int,int> > inp;
int dp[K][N],lv[N],pa[N];
bool visited[N];

int root(int x){ if(pa[x]==x) return x; return pa[x] = root(pa[x]); }

void dfs(int u,int p)
{
    lv[u] = lv[p]+1,dp[0][u] = p;
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

int dist(int a,int b)
{
    int l = lca(a,b);
    return lv[a]+lv[b]-lv[l]-lv[l];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        int t,x,y;
        cin >> t;
        if(t==1) cin >> x >> y,adj[x].insert(y),adj[y].insert(x);
        else if(t==2) cin >> x;
        else cin >> x >> y;
        inp.push_back({t,x,y});
    }
    for(int i = 1;i <= n;i++) if(!lv[i]) dfs(i,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    for(int i = 1;i <= n;i++) pa[i] = i;
    for(auto [t,x,y] : inp)
    {
        if(t==1) pa[root(x)] = root(y);
        else if(t==2) pa[root(x)] = x,pa[x] = x;
        else
        {
            if(dist(x,root(x))<dist(y,root(x))) cout << x << '\n';
            else cout << y << '\n';
        }
    }
}
