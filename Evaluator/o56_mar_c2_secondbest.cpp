#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 20;

int n,m;
long long mst,ans = LLONG_MAX;
vector<pair<int,int> > adj[N];
priority_queue<tuple<int,int,int> > ed;
vector<tuple<int,int,int> > nm;
int pa[N],dp[K][N],lv[N];
long long res[K][N];

int root(int x){ if(pa[x]==x) return x; return pa[x] = root(pa[x]); }

void dfs(int u,int p,int l,int w)
{
    dp[0][u] = p,res[0][u] = w,lv[u] = l;
    for(auto [w,v] : adj[u]) if(v!=p) dfs(v,u,l+1,w);
}

long long lca(int a,int b)
{
    long long ret = 0;
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) ret = max(ret,res[i][a]),a = dp[i][a];
    if(a==b) return ret;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) ret = max(ret,max(res[i][a],res[i][b])),a = dp[i][a],b = dp[i][b];
    ret = max(ret,res[0][a]),ret = max(ret,res[0][b]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) pa[i] = i;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        ed.push({-d,a,b});
    }
    while(!ed.empty())
    {
        auto [d,a,b] = ed.top();
        ed.pop();
        d = -d;
        if(root(a)==root(b)){ nm.push_back({d,a,b}); }
        else 
        {
            mst+=d;
            adj[a].push_back({d,b});
            adj[b].push_back({d,a});
            pa[root(a)] = root(b);
        }
    }
    dfs(1,0,1,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]],res[i][j] = max(res[i-1][j],res[i-1][dp[i-1][j]]);
    for(auto [d,a,b] : nm)
    {
        long long tmp = lca(a,b);
        ans = min(ans,d-tmp);
    }
    cout << ans+mst;
}
