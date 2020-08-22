#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N];
int pa[N],c[N],l[N];
int sz[N],big[N];
set<pair<int,int> > used,lft;
long long sum,ans;

void pre(int u){ sz[u] = 1; for(int v : adj[u]) pre(v),sz[u]+=sz[v]; }

void add(int u,int k)
{       
    if(k==1)
    {
        auto it = used.end(); 
        if(sum+c[u]<=m) sum+=c[u],used.insert({c[u],u});
        else if(!used.empty() and c[u]<(*(--it)).first) sum-=(*it).first,sum+=c[u],used.insert({c[u],u}),lft.insert(*it),used.erase(*it);
        else lft.insert({c[u],u});
    }
    else
    {
        if(used.find({c[u],u})!=used.end())
        {
            sum-=c[u],used.erase({c[u],u});
            if(!lft.empty() and (*lft.begin()).first+sum<=k) used.insert(*lft.begin()),sum+=(*lft.begin()).second,lft.erase(lft.begin());
        }       
        else lft.erase({c[u],u});
    }
    for(int v : adj[u]) if(!big[v]) add(v,k);
}

void dfs(int u,int k)
{
    int mx = -1,bc = -1;
    for(int v : adj[u]) if(sz[v]>mx) mx = sz[v],bc = v;
    for(int v : adj[u]) if(v!=bc) dfs(v,0);
    if(bc!=-1) dfs(bc,1),big[bc] = 1;
    add(u,1);
    ans = max(ans,(long long)l[u]*int(used.size()));
    if(bc!=-1) big[bc] = 0;
    if(!k) add(u,0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> pa[i] >> c[i] >> l[i];
        adj[pa[i]].push_back(i);   
    }
    pre(1);
    dfs(1,1);
    cout << ans;
}
