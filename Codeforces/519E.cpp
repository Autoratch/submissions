#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 20;

int n,q;
vector<int> adj[N];
int lv[N],dp[K][N],sz[N];

void dfs(int u,int p,int l)
{
    lv[u] = l,dp[0][u] = p,sz[u] = 1;
    for(int v : adj[u]) if(v!=p) dfs(v,u,l+1),sz[u]+=sz[v];
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int jump(int a,int l)
{
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=l) a = dp[i][a];
    return a;
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
    dfs(1,0,1);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int l = lca(a,b);
        if(lv[a]<lv[b]) swap(a,b);
        if((lv[a]-lv[l]+lv[b]-lv[l])%2){ cout << "0\n"; continue; }
        int di = lv[a]-lv[l]+lv[b]-lv[l]; di/=2; 
        int xa = jump(a,lv[a]-di+1),ya = dp[0][xa],xb = jump(b,lv[b]-di+1);
        if(a==b) cout << n << '\n';
        else if(lv[a]==lv[b]) cout << n-sz[xa]-sz[xb] << '\n';
        else cout << sz[ya]-sz[xa] << '\n';
    }
}
