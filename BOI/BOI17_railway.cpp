#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,k;
vector<int> adj[N],rail[N];
int am[N],sz[N],big[N],cnt[N],pa[N];
int now,ans[N];
map<pair<int,int>,int> id;
vector<int> an;

void pre(int u,int p){ sz[u] = 1,pa[u] = p; for(int v : adj[u]) if(v!=p) pre(v,u),sz[u]+=sz[v]; }

void add(int u,int p,int k)
{
    for(int x : rail[u])
    {
        if(!cnt[x] or cnt[x]==am[x]) now++;
        cnt[x]+=k;
        if(!cnt[x] or cnt[x]==am[x]) now--;
    }
    for(int v : adj[u]) if(v!=p and !big[v]) add(v,u,k);
}

void dfs(int u,int p,int k)
{
    int bc = -1,mx = -1;
    for(int v : adj[u]) if(v!=p) if(sz[v]>mx) mx = sz[v],bc = v;
    for(int v : adj[u]) if(v!=p and v!=bc) dfs(v,u,0);
    if(bc!=-1) dfs(bc,u,1),big[bc] = 1;
    add(u,p,1);
    ans[u] = now;
    if(bc!=-1) big[bc] = 0;
    if(!k) add(u,p,-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        id[{a,b}] = id[{b,a}] = i+1;
    }
    for(int i = 1;i <= m;i++)
    {
        cin >> am[i];
        for(int j = 0;j < am[i];j++)
        {
            int x;
            cin >> x;
            rail[x].push_back(i);
        }
    }
    pre(1,0);
    dfs(1,0,1);
    for(int i = 2;i <= n;i++)
    {
        if(ans[i]>=k) an.push_back(id[{i,pa[i]}]);
    }
    sort(an.begin(),an.end());
    cout << an.size() << '\n';
    for(int x : an) cout << x << ' ';
}
