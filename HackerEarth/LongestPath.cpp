#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,k,res[N],mx,id,ans;
vector<int> adj[N];
bool visited[N];

void dfs(int u,int p,int x)
{
    visited[u] = true;
    if(x>mx) mx = x,id = u;
    for(int v : adj[u]) if(v!=p) dfs(v,u,x+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> res[i];
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        if(res[a]%k or res[b]%k) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1;i <= n;i++) 
    {
        if(visited[i] or res[i]%k) continue;
        mx = 0;
        dfs(i,0,0);
        mx = 0;
        dfs(id,0,0);
        ans = max(ans,mx);
    }

    cout << ans;
}
