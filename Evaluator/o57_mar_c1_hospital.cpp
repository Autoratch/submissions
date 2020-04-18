#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
vector<int> adj[N];
int res[N];
long long ans;

void dfs(int u,int p,int l)
{
    res[u] = 1;
    ans+=l;
    for(int v : adj[u]) if(v!=p) dfs(v,u,l+1),res[u]+=res[v];
}

void dfs2(int u,int p)
{
    for(int v : adj[u]) if(v!=p) if(res[v]>n-1-res[v]){ ans+=n-res[v]; ans-=res[v]; return void(dfs2(v,u)); }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,0);
    dfs2(1,0);
}
