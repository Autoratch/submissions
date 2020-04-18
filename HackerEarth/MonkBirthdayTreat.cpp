#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int n,m,each,ans = INT_MAX;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    each++;
    for(int v : adj[u]) dfs(v);
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
    }

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++) visited[j] = false;
        each = 0;
        dfs(i);
        ans = min(ans,each);
    }

    cout << ans;
}
