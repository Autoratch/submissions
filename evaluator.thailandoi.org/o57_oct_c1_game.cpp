#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;

int n,m,mx,lf;
int lv[N],ans[N];
bool visited[N];
vector<int> adj[N],rev[N];
stack<int> st,tmp;

void dfs(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    for(int v : adj[u]) dfs(v);
    st.push(u);
}

void scc(int u)
{
    if(visited[u]){ mx = max(mx,lv[u]); return; }
    visited[u] = true;
    for(int v: rev[u]) scc(v);
    tmp.push(u);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    lf = n;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for(int i = 0;i < n;i++) dfs(i);

    memset(visited,0,sizeof visited);

    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(visited[u]) continue;
        mx = 0;
        scc(u);
        mx++;
        while(!tmp.empty())
        {
            int x = tmp.top();
            tmp.pop();
            lv[x] = mx;
            ans[mx]++;
            lf--;
        }
    }

    ans[1]+=lf;
    for(int i = 1;ans[i] != 0;i++) cout << ans[i] << ' ';
}
