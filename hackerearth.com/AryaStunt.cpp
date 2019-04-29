#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;

int n,m,a[N],am,mx,dead,inj,id;
vector<int> adj[N];
set<int> ans;
bool visited[N];

void dfs(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    if(a[u]>mx) mx = a[u],id = u;
    else if(a[u]==mx) id = min(id,u);
    am+=a[u];
    for(int v : adj[u]) dfs(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1;i <= n;i++)
    {
        if(visited[i]) continue;
        am = mx = 0;
        dfs(i);
        dead+=mx;
        inj+=am-mx;
        ans.insert(id);
    }   

    cout << dead << ' ' << inj << '\n';
    for(int x : ans) cout << x << ' ';
}
