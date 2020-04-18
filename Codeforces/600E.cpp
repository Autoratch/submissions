#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
vector<int> adj[N];
bool big[N];
int col[N],sz[N],cnt[N];
long long ans[N],now,mxx;

void pre(int u,int p){ sz[u] = 1; for(int v : adj[u]) if(v!=p) pre(v,u),sz[u]+=sz[v]; }

void add(int u,int p,int x)
{ 
    cnt[col[u]]+=x;  
    if(cnt[col[u]]>mxx) mxx = cnt[col[u]],now = col[u];
    else if(cnt[col[u]]==mxx) now+=col[u];
    for(int v : adj[u]) if(v!=p and !big[v]) add(v,u,x); 
}

void dfs(int u,int p,bool k)
{
    int bc = -1,mx = -1;
    for(int v : adj[u]) if(v!=p) if(sz[v]>mx) mx = sz[v],bc = v;
    for(int v : adj[u]) if(v!=p and v!=bc) dfs(v,u,0);
    if(bc!=-1) dfs(bc,u,1),big[bc] = 1;
    add(u,p,1);
    ans[u] = now;
    if(bc!=-1) big[bc] = 0;
    if(!k) add(u,p,-1),mxx = 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> col[i];
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pre(1,0);
    dfs(1,0,1);
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}
