#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 33;

int n,k,cn;
vector<int> adj[N],rev[N];
set<int> rea[N],test;
int deg[N],cnt,idx[N];
stack<int> st;
bool visited[N],useful[N];

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
    idx[u] = cnt;
    for(int v : rev[u]) scc(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= k;j++)
    {
        char c; 
        cin >> c;
        if(c=='1') adj[i].push_back(j+n),rev[j+n].push_back(i);
        else adj[j+n].push_back(i),rev[i].push_back(j+n);
    }
    for(int i = 1;i <= n+k;i++) dfs(i);
    for(int i = 1;i <= n+k;i++) visited[i] = false;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(visited[u]) continue;
        ++cnt;
        scc(u);
    }
    for(int i = 1;i <= n+k;i++) for(int j : adj[i]) if(idx[i]!=idx[j]) rea[idx[i]].insert(idx[j]);
    for(int i = 1;i <= n;i++) useful[idx[i]] = true;
    for(int i = 1;i <= cnt;i++) if(useful[i]) for(int x : rea[i]) deg[x]++;
    for(int i = 1;i <= n;i++) if(!deg[idx[i]]) test.insert(idx[i]);
    cn = test.size();
    if(cn!=1){ cout << "-1"; return 0; }
    for(int i = 1;i <= n;i++) if(!deg[idx[i]]) cout << i << ' ';
}
