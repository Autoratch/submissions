#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n,m,s,p,res[N],pub[N],sum[N],ans,puu[N];
vector<int> adj[N];
set<int> tre[N];
int dis[N],low[N],cnt,cc;
bool marked[N];
int deg[N],val[N],id[N];
queue<int> q;
vector<int> topo;
vector<int> st;
int used[N];

void dfs(int u)
{
    dis[u] = low[u] = ++cnt;
    st.push_back(u);
    marked[u] = true;
    for(int v : adj[u])
    {
        if(!dis[v]) dfs(v),low[u] = min(low[u],low[v]);
        else if(marked[v]) low[u] = min(low[u],dis[v]);
    }
    if(dis[u]==low[u])
    {
        int v = ++cc;
        do
        {
            v = st.back(),st.pop_back();
            id[v] = cc,marked[v] = 0;
        }while(v!=u);
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
    }
    for(int i = 1;i <= n;i++) cin >> res[i];
    cin >> s >> p;
    for(int i = 1;i <= p;i++){ int x; cin >> x,puu[x] = true; }
    for(int i = 1;i <= n;i++) if(!dis[i]) dfs(i);
    for(int i = 1;i <= n;i++) sum[id[i]]+=res[i],pub[id[i]]|=puu[i];
    for(int i = 1;i <= n;i++) 
    {
        for(int j : adj[i])
        {
            int a = id[i],b = id[j];
            if(a!=b) tre[a].insert(b);
        }
    }
    st.clear();
    for(int i = 1;i <= n;i++) if(!used[id[i]]){ for(int x : tre[id[i]]) deg[x]++; used[id[i]] = true; }
    for(int i = 1;i <= cc;i++) if(!deg[i]) q.push(i);
    for(int i = 1;i <= cc;i++) if(i!=id[s]) val[i] = INT_MIN;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        st.push_back(u);
        for(int v : tre[u])
        {
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
    }
    for(int x : st)
    {
        sum[x]+=val[x];
        if(pub[x]) ans = max(ans,sum[x]);
        for(int y : tre[x]) val[y] = max(val[y],sum[x]);
    }
    cout << ans;
}
