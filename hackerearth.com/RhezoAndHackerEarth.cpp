#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,q;
vector<int> adj[N];
int disc[N],low[N];
bool visited[N];
bool ans[N];
map<pair<int,int>,int> ma;
int idx;

void dfs(int u,int p)
{
    visited[u] = true;
    low[u] = disc[u] = ++idx;
    int ch = 0;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            ch++;
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>disc[u]) ans[ma[{u,v}]] = true;
        }
        else if(v!=p) low[u] = min(low[u],disc[v]);
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
        ma[{a,b}] = ma[{b,a}] = i;
    }

    cin >> q;

    for(int i = 1;i <= n;i++) if(!visited[i]) dfs(i,0);

    while(q--) 
    {
        int x;
        cin >> x;
        x--;
        if(ans[x]) cout << "Unhappy\n";
        else cout << "Happy\n";
    }
}
