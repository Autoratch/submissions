#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,m;
int deg[N],mxd,id;
vector<int> adj[N];
vector<pair<int,int> > ed;
bool visited[N];
queue<pair<int,int> > q;

void bfs()
{
    q.push({id,id});
    visited[id] = true;
    while(!q.empty())
    {
        int u = q.front().first,p = q.front().second;
        q.pop();
        if(u!=p) ed.push_back({u,p});
        for(int i = 0;i < adj[u].size();i++)
        {
            if(visited[adj[u][i]]) continue;
            visited[adj[u][i]] = true;
            q.push({adj[u][i],u});
        }
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
        deg[a]++;
        deg[b]++;
        if(deg[a]>mxd){ mxd = deg[a]; id = a; }
        if(deg[b]>mxd){ mxd = deg[b]; id = b; }
    }

    bfs();

    for(int i = 0;i < ed.size();i++) cout << ed[i].first << ' ' << ed[i].second << '\n';
}
