#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,k;
int val[N],res[N];
vector<int> adj[N],st[N];

void dfs(int u,int p)
{
    int id = st[val[u]].size()-k;
    if(id>=0) res[u] = st[val[u]][id];
    st[val[u]].push_back(u);
    for(int v : adj[u]) if(v!=p) dfs(v,u);
    st[val[u]].erase(st[val[u]].end()-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++) cin >> val[i],res[i] = -1;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);    

    for(int i = 1;i <= n;i++) cout << res[i] << ' ';    
}
