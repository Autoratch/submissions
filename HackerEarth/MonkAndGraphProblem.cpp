#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,ans;
vector<int> adj[N];
bool visited[N];
int self[N];
vector<int> now;

void dfs(int u,int p)
{
    if(visited[u]) return;
    visited[u] = true;
    now.push_back(u);
    for(int v : adj[u])
    {
        if(v==p) continue;
        dfs(v,u);
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
        if(a==b){ self[a]++; continue; }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1;i <= n;i++)
    {
        if(visited[i]) continue;
        now.resize(0);
        dfs(i,0);
        int sel = 0,ad = 0;
        for(int x : now) sel+=self[x],ad+=adj[x].size();
        ans = max(ans,sel+ad/2);
    }

    cout << ans;
}
