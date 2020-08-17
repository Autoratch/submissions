#include "factories.h"
#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 1;
const int K = 19;
 
vector<pair<int,int> > adj[N];
int sz[N],lv[N],dp[K][N],pa[N],lcc[N][K];
long long dis[N];
vector<pair<long long,int> > diss[N];
bool blocked[N];
long long res[N][2],ans;
vector<int> rev;
 
void dfs(int u,int p)
{
    dp[0][u] = p,lv[u] = lv[p]+1;
    for(auto [d,v] : adj[u]) if(v!=p) dis[v] = dis[u]+d,dfs(v,u);
}
 
void getsz(int u,int p,int st,long long w)
{ 
    sz[u] = 1; 
    if(st!=-1) diss[u].push_back({w,st}); 
    for(auto [d,v] : adj[u]) if(v!=p and !blocked[v]) getsz(v,u,st,w+d),sz[u]+=sz[v]; 
}
 
void build(int u,int cp)
{
    getsz(u,cp,-1,0);
    int c = u,prev = 0;
    while(true)
    {
        int mx = -1,r = 0;
        for(auto [d,v] : adj[c]) if(v!=prev and !blocked[v] and sz[v]>mx) mx = sz[v],r = v;
        if(mx*2>sz[u]) prev = c,c = r;
        else break;
    }
    getsz(c,c,c,0);
    pa[c] = cp,blocked[c] = true;
    for(auto [d,v] : adj[c]) if(!blocked[v]) build(v,c);
}
  
void Init(int n,int a[],int b[],int d[]) 
{
    for(int i = 0;i < n-1;i++) a[i]++,b[i]++;
    for(int i = 0;i < n-1;i++)
    {
        adj[a[i]].push_back({d[i],b[i]});
        adj[b[i]].push_back({d[i],a[i]});
    }
    dfs(1,0);
    build(1,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    for(int i = 1;i <= n;i++) res[i][0] = res[i][1] = 1e18;
}
 
long long dist(int a,int b,int cn)
{
    int l = lcc[a][cn];
    return dis[a]+dis[b]-dis[l]-dis[l]; 
}
 
void upd(int t,int x)
{
    for(auto [d,u] : diss[x])
    {
        rev.push_back(u);
        res[u][t] = min(res[u][t],d);
    }
}
 
long long Query(int s,int x[],int t,int y[]) 
{
    for(int i = 0;i < s;i++) x[i]++;
    for(int i = 0;i < t;i++) y[i]++;
    ans = LLONG_MAX;
    for(int i = 0;i < s;i++) upd(0,x[i]);
    for(int i = 0;i < t;i++) upd(1,y[i]);
    for(int x : rev) ans = min(ans,res[x][0]+res[x][1]),res[x][0] = res[x][1] = 1e18;
    rev.clear();
    return ans;
}
