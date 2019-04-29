#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int K = 20;

int n,ans;
vector<int> adj[N];
int val[N],res[N][K];

void dfs(int u,int p)
{
    for(int i = 0;i < K;i++) res[u][i] = (val[u] >> i)&1;
    for(int v : adj[u])
    {
        if(v==p) continue;
        dfs(v,u);  
        for(int i = 0;i < K;i++) res[u][i]+=res[v][i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> val[i];
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,0);

    for(int i = 2;i <= n;i++)
    {
        bool e = 1;
        for(int j = 0;j < K;j++) e&=(bool)res[i][j]==bool(res[1][j]-res[i][j]);
        ans+=e;
    }

    cout << ans;
}
