#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int res[N],sum,ans,mn = INT_MAX;
vector<int> adj[N];

void dfs(int u,int p)
{
    int each = 0;
    for(int v : adj[u]) if(v!=p) dfs(v,u),each = max(each,res[v]),res[u]+=res[v];
    each = max(each,sum-res[u]);
    if(each<mn) mn = each,ans = u;
}

int LocateCentre(int n,int p[],int s[],int d[])
{
    for(int i = 0;i < n;i++) res[i+1] = p[i],sum+=res[i+1];
    for(int i = 0;i < n-1;i++)
    {
        s[i]++,d[i]++;
        adj[s[i]].push_back(d[i]);
        adj[d[i]].push_back(s[i]);
    }
    dfs(1,0);
    return ans-1;
}
