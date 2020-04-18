#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N],rev[N],dag[N];
vector<pair<int,int> > ed;
bool visited[N];
stack<int> st;
vector<int> tmp;
int idx[N],id,lv[N],dist[N];
queue<int> q;
int ans;

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
        ed.push_back({a,b});
    }

    for(int i = 1;i <= n;i++) dfs(i);

    for(int i = 1;i <= n;i++) visited[i] = false;

    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(visited[x]) continue;
        tmp.resize(0);
        scc(x);
        for(int x : tmp) idx[x] = id;
        id++;
    }

    for(pair<int,int> ab : ed)
    {
        int a = ab.first,b = ab.second;
        if(idx[a]==idx[b]) continue;
        dag[idx[a]].push_back(idx[b]);
        lv[idx[b]]++;
    }

    for(int i = 0;i < id;i++) if(lv[i]==0) q.push(i);

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        ans = max(ans,dist[p]);
        for(int v : dag[p])
        {
            if(lv[v]<=0) continue;
            lv[v]--;
            dist[v] = max(dist[v],dist[p]+1);
            if(lv[v]==0) q.push(v);
        }
    }

    cout << ans;
}   