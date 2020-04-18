#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
int deg[N];
bool visited[N];
vector<int> adj[N];
queue<int> q;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    for(int i = 1;i <= n;i++) if(deg[i]==0) q.push(i),visited[i] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v : adj[u])
        {
            if(visited[v]) continue;
            deg[v]--;
            if(deg[v]==0) q.push(v),visited[v] = true;
        }
    }

    if(ans.size()<n) cout << "no";
    else for(int x : ans) cout << x << '\n';
}
