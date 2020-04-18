#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N];
bool visited[N];
int lv[N];

bool dfs(int u,int l)
{
    if(visited[u]) return !(lv[u]==l);
    visited[u] = true,lv[u] = l;
    for(int v : adj[u]) if(dfs(v,3-l)) return true;
    return false;
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

    for(int i = 0;i < n;i++) if(!visited[i]) if(dfs(i,1)){ cout << "Gay found!"; return 0; }
    
    cout << "Gay not found!";
}
