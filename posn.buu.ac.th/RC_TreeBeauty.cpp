#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,s[N];
vector<int> adj[N],res;

void dfs(int u,int p)
{
    res.push_back(s[u]);
    for(int v : adj[u]) if(v!=p) dfs(v,u);
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

    int mn = INT_MAX;

    for(int i = 1;i <= n;i++) cin >> s[i],mn = min(mn,s[i]);

    int x;

    for(int i = 1;i <= n;i++) if(adj[i].size()==1) x = i;

    dfs(x,0);

    
}
