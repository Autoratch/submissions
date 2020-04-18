#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,ans;
vector<int> adj[N];
bool visited[N];

void dfs(int u,int p)
{
    if(visited[u]) return;
    visited[u] = true;
    int cu = adj[u].size();
    if(u!=p) cu--;
    for(int v : adj[u])
    {
        if(v==p) continue;
        dfs(v,u);
        int cv = adj[v].size()-1;
        if(cv>cu) ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1;i <= n;i++) if(!visited[i]) dfs(i,i);

    cout << ans;
}
