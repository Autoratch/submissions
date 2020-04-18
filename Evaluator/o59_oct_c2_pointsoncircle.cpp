#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int k,n,st;
int pa[N];
vector<tuple<int,int,int> > ed;
vector<pair<int,int> > adj[N];
int ans[N];

int root(int x){ if(pa[x]==x) return x; else return pa[x] = root(pa[x]); }

void dfs(int u,int p,int x)
{
    ans[u] = x;
    for(auto pi : adj[u]) if(pi.second!=p) dfs(pi.second,u,x+pi.first);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    {
        int x;
        cin >> x;
        if(i!=j) ed.push_back({x,i,j});
    }

    for(int i = 0;i < n;i++) pa[i] = i;

    sort(ed.begin(),ed.end());

    for(auto x : ed)
    {
        int d,a,b; tie(d,a,b) = x;
        if(root(a)==root(b)) continue;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
        pa[root(a)] = root(b);
    }

    for(int i = 0;i < n;i++) if(adj[i].size()==1) st = i;

    dfs(st,st,0);

    for(int i = 0;i < n;i++) cout << ans[i] << '\n';
}
