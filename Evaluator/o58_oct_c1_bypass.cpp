#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
vector<int> adj[N];
int res[N],pa[N];
long long ans;

void dfs(int u,int p)
{
    res[u] = 1;
    pa[u] = p;
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i];
        if(v==p) continue;
        dfs(v,u);
        res[u]+=res[v];
    }
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
    }

    dfs(1,1);

    for(int i = 1;i <= n;i++)
    {
        int u = i,cnt = 0;
        long long up = n-res[u],mx = 0,mx2 = 0;
        for(int j = 0;j < adj[u].size();j++)
        {
            if(adj[u][j]==pa[u]) continue;
            if(res[adj[u][j]]==mx) cnt++;
            else if(res[adj[u][j]]>mx){ cnt = 1; mx2 = mx; mx = res[adj[u][j]]; }
            else if(res[adj[u][j]]>mx2) mx2 = res[adj[u][j]]; 
        }
        for(int j = 0;j < adj[u].size();j++)
        {
            int v = adj[u][j];
            if(v==pa[u]) continue;
            long long ul,dw = 0;
            if(cnt>1 or res[adj[u][j]]!=mx) ul = mx;
            else ul = mx2;
            for(int k = 0;k < adj[v].size();k++) if(adj[v][k]!=u) dw = max(dw,(long long)res[adj[v][k]]);
            ans = max(ans,dw*max(up,ul));
        }
    }

    cout << ans;
}
