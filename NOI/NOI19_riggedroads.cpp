#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
const int K = 20;

int n,m;
vector<pair<int,int> > adj[N];
pair<int,int> ed[N];
int pa[N],dp[K][N],id[N],lv[N];
int now,ans[N];
vector<int> res;
bool rigged[N];

void dfs(int u,int p,int t)
{
    dp[0][u] = pa[u] = p,id[u] = t,lv[u] = lv[p]+1;
    for(auto [t,v] : adj[u]) if(v!=p) dfs(v,u,t);
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> ed[i].first >> ed[i].second;
    for(int i = 0;i < n-1;i++)
    { 
        int x; cin >> x; 
        rigged[x] = true; 
        adj[ed[x].first].push_back({x,ed[x].second}),adj[ed[x].second].push_back({x,ed[x].first}); 
    }
    dfs(1,0,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    for(int i = 1;i <= m;i++) if(!ans[i])
    {
        if(rigged[i]) 
        {
            ans[i] = ++now;
            int a = ed[i].first,b = ed[i].second;
            if(lv[a]>lv[b]) swap(a,b);
            id[b] = id[a],pa[b] = pa[a];
        }
        else
        {
            int a = ed[i].first,b = ed[i].second,aa = a,bb = b;
            int l = lca(a,b);
            res.clear();
            while(lv[pa[a]]>=lv[l]){ if(!ans[id[a]]) res.push_back(id[a]); a = pa[a]; }
            while(lv[pa[b]]>=lv[l]){ if(!ans[id[b]]) res.push_back(id[b]); b = pa[b]; }
            id[aa] = id[bb] = id[a],pa[aa] = pa[bb] = pa[a];
            sort(res.begin(),res.end());
            for(int x : res) ans[x] = ++now;
            ans[i] = ++now;
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
}
