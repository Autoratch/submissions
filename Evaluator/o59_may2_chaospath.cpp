#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
vector<int> adj[N];
vector<pair<int,int> > ed;
long long res[N],sz[N],ans;

void dfs(int u,int p)
{  
    sz[u] = 1;
    for(int v : adj[u]) if(v!=p) dfs(v,u),sz[u]+=sz[v];
}

void solve(int u,int p)
{
    long long mx = 0,mx2 = 0;
    for(int v : adj[u]) if(v!=p)
    {
        solve(v,u);
        if(res[v]>mx) mx2 = mx,mx = res[v];
        else if(res[v]>mx2) mx2 = res[v];
    }
    ans = max(ans,mx+mx2);
    res[u]+=max(mx,mx2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ed.push_back({a,b});
    }
    dfs(1,0);
    for(auto [a,b] : ed)
    {
        if(sz[a]<sz[b]) swap(a,b);
        long long x = n-sz[b],y = sz[b];
        res[b] = x*y;
    }
    solve(1,0);
    cout << ans;
}
