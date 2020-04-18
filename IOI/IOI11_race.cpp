#include "race.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int K = 19;

int n,k,cn;
vector<pair<int,int> > adj[N];
vector<int> cen[N];
int sz[N],pa[N],ans = INT_MAX;
bool blocked[N];
int dist[N];
map<int,int> res;

void dfs(int u,int p){ sz[u] = 1; for(auto [d,v] : adj[u]) if(v!=p and !blocked[v]) dfs(v,u),sz[u]+=sz[v]; }

void build(int u,int cp)
{
    dfs(u,0);
    int c = u,prev = 0;
    while(true)
    {
        int mx = 0,id = 0;
        for(auto [d,v] : adj[c]) if(!blocked[v] and v!=prev) if(sz[v]>mx) mx = sz[v],id = v;
        if(mx*2>=sz[u]) prev = c,c = id;
        else break;
    }
    if(cp==0) cn = c;
    pa[c] = cp;
    if(cp) cen[cp].push_back(c);
    blocked[c] = true;
    for(auto [d,v] : adj[c]) if(!blocked[v]) build(v,c);
}

void upd(int u,int p,bool f,int all,int len)
{
    if(all>k) return;
    if(!f)
    {
        if(all==k) ans = min(ans,len);
        else if(res[k-all]) ans = min(ans,res[k-all]+len);
    }
    else if(res[all]==0 or res[all]>len) res[all] = len;
}

void sol(int c,int u,int p,int t,int w,int lv)
{
    upd(u,c,t,w,lv);
    for(auto [d,v] : adj[u]) if(!blocked[v] and v!=p) sol(c,v,u,t,w+d,lv+1);
}

void run(int u)
{
    for(auto [d,v] : adj[u]) if(!blocked[v])
    {
        sol(u,v,u,0,d,1);
        sol(u,v,u,1,d,1);
    }
    res.clear();
    blocked[u] = true;
    for(int v : cen[u]) run(v);
}

int best_path(int nn,int kk,int h[][2],int l[])
{
    n = nn,k = kk;
    for(int i = 0;i < n-1;i++)
    {
        int a = h[i][0],b = h[i][1],d = l[i]; a++,b++;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }
    build(1,0);
    fill(blocked,blocked+n+1,0);
    run(cn);
    if(ans==INT_MAX) ans = -1;
    return ans;
}

