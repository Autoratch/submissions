#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 1;

int n,k,all,lwsep;
vector<int> adj[N];
int res[N],sz[N],am[N],now[N];
bool big[N],sep[N],warn;
int allt,fult;
int sepsub[N];

void pre(int u,int p){ sz[u] = 1; for(int v : adj[u]) if(v!=p) pre(v,u),sz[u]+=sz[v]; }

void add(int u,int p,int x)
{
    if(now[res[u]]==am[res[u]]) fult--;
    if(now[res[u]]==0) allt++;
    now[res[u]]+=x;
    if(now[res[u]]==am[res[u]]) fult++;
    if(now[res[u]]==0) allt--;
    for(int v : adj[u]) if(v!=p and !big[v]) add(v,u,x);
}

void dfs(int u,int p,bool k)
{
    int mx = 0,bc = -1;
    for(int v : adj[u]) if(v!=p) if(sz[v]>mx) mx = sz[v],bc = v;
    for(int v : adj[u]) if(v!=p) if(v!=bc) dfs(v,u,0);
    if(bc!=-1) dfs(bc,u,1),big[bc] = 1;
    add(u,p,1);
    sep[u] = (allt==fult);
    if(sep[u] and u>1) all++;
    if(bc!=-1) big[bc] = 0;
    if(!k) add(u,p,-1);
}

void pres(int u,int p)
{ 
    sepsub[u] = sep[u]; 
    for(int v : adj[u]) if(v!=p) pres(v,u),sepsub[u]+=sepsub[v]; 
    if(sepsub[u]==all and sep[u]) warn = true;
    if(sepsub[u]==1 and sep[u] and u!=1) lwsep++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++) cin >> res[i],am[res[i]]++;
    pre(1,0);
    dfs(1,0,1);
    pres(1,0);
    if(!warn) cout << (lwsep+1)/2;
    else if(lwsep%2==1) cout << (lwsep+1)/2;
    else cout << lwsep/2+1;
}
