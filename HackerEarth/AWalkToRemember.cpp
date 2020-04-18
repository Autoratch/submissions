#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N],rev[N];
stack<int> st;
bool visited[N];
vector<int> tmp;
int ans[N];

void dfs(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    for(int v : adj[u]) dfs(v);
    st.push(u);
}

void scc(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    for(int v : rev[u]) scc(v);
    tmp.push_back(u);
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
        rev[b].push_back(a);
    }

    for(int i = 1;i <= n;i++) dfs(i);

    for(int i = 1;i <= n;i++) visited[i] = false;

    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        tmp.resize(0);
        scc(x);
        if(tmp.size()==1) continue;
        for(int y : tmp) ans[y] = 1;
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}
