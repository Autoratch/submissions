#include <bits/stdc++.h>
using namespace std;

const int N = 3001;
const int K = 17;

int n;
int pa[N];
vector<tuple<int,int,int> > ed,im,nm,ans;
vector<pair<int,int> > adj[N];
int dp[K][N],lv[N],res[N];

int root(int x){ if(pa[x]==x) return x; else return pa[x] = root(pa[x]); }

void dfs(int u,int p,int l)
{
    lv[u] = l,dp[0][u] = p;
    for(auto it : adj[u]) 
    {
        int v = it.second,d = it.first;
        if(v==p) continue;
        res[v] = res[u]+d;
        dfs(v,u,l+1);
    }
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int dist(int a,int b){ return res[a]+res[b]-2*res[lca(a,b)]; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(i!=j){ int x; cin >> x; if(i<j) ed.push_back({x,i,j}); }

    sort(ed.begin(),ed.end());

    for(int i = 1;i <= n;i++) pa[i] = i;

    for(auto it : ed)
    {
        int d,a,b; tie(d,a,b) = it;
        if(root(a)==root(b)) nm.push_back(it);
        else pa[root(a)] = root(b),im.push_back(it);
    }

    for(auto it : im){ int d,a,b; tie(d,a,b) = it; adj[a].push_back({d,b}),adj[b].push_back({d,a}); }

    dfs(1,0,1);

    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];

    for(auto it : nm){ int d,a,b; tie(d,a,b) = it; if(dist(a,b)!=d){ im.push_back(it); break; } }

    sort(im.begin(),im.end());

    for(auto it : im){ int d,a,b; tie(d,a,b) = it; ans.push_back({a,b,d}); }

    sort(ans.begin(),ans.end());

    for(auto it : ans){ int d,a,b; tie(a,b,d) = it; cout << a << ' ' << b << ' ' << d << '\n'; }
}
