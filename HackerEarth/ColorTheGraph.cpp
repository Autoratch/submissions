#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n,m,cn,am,ans,lv[N];
vector<int> adj[N];
bool visited[N],ok;

void dfs(int u,int x)
{
    if(visited[u]) return;
    visited[u] = true;
    lv[u] = x;
    if(x==1) cn++;
    am++;
    for(int v : adj[u]) 
    {
        if(lv[u]==lv[v]) ok = false; 
        dfs(v,3-x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        for(int i = 1;i <= n;i++) adj[i].clear(),visited[i] = false,lv[i] = 0;
        for(int i = 0;i < m;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ok = true;
        ans = 0;
        for(int i = 1;i <= n;i++) if(!visited[i])
        {
            am = cn = 0;
            dfs(i,1);
            ans+=max(cn,am-cn);
        }
        if(!ok) cout << "NO\n";
        else cout << ans << '\n';
    }
}
