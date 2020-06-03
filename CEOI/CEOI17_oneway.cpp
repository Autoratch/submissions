#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 19;

int n,m,p;
vector<int> adj[N];
map<pair<int,int>,int> mul; 
map<pair<int,int>,pair<int,char> > hsh;
bool visited[N];
int res[N],lv[N],dp[K][N];
int rec[N];
string ans;

void dfs(int u,int p)
{
    if(visited[u]) return;
    visited[u] = true;
    lv[u] = lv[p]+1,dp[0][u] = p;
    for(int v : adj[u]) if(v!=p) dfs(v,u);
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

void solve(int u,int p)
{
    if(visited[u]){ res[u]++,res[p]++,res[lca(u,p)]-=2; return; }
    visited[u] = true;
    for(int v : adj[u]) if(v!=p) solve(v,u);
}

void sum(int u,int p)
{
    if(visited[u]) return;
    visited[u] = true;
    for(int v : adj[u]) if(v!=p) sum(v,u);
    res[p]+=res[u];
}

void run(int u,int p)
{
    if(visited[u]) return;
    visited[u] = true;
    for(int v : adj[u]) if(v!=p) run(v,u);
    rec[p]+=rec[u];
    if(mul[{min(u,p),max(u,p)}]>1) return;
    if(res[u]) return;
    if(rec[u]>0) ans[hsh[{u,p}].first] = hsh[{u,p}].second;
    else if(rec[u]<0) ans[hsh[{p,u}].first] = hsh[{p,u}].second;
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
        adj[b].push_back(a);
        hsh[{a,b}] = {i,'R'};
        hsh[{b,a}] = {i,'L'};
        mul[{min(a,b),max(a,b)}]++;
    }
    for(int i = 1;i <= n;i++) if(!visited[i]) dfs(i,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] =  dp[i-1][dp[i-1][j]];
    for(int i = 1;i <= n;i++) visited[i] = false;
    for(int i = 1;i <= n;i++) if(!visited[i]) solve(i,0);
    for(int i = 1;i <= n;i++) visited[i] = false;
    for(int i = 1;i <= n;i++) if(!visited[i]) sum(i,0);
    cin >> p;
    while(p--)
    {
        int a,b;
        cin >> a >> b;
        rec[a]++,rec[b]--;
    }
    for(int i = 1;i <= n;i++) visited[i] = false;
    ans.resize(m);
    for(int i = 1;i <= n;i++) run(i,0);
    for(int i = 0;i < m;i++) if(ans[i]!='L' and ans[i]!='R') ans[i] = 'B';
    cout << ans;
}
