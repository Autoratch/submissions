#include <bits/stdc++.h>
using namespace std;
#define ti tuple<int,int,int>

const int N = 2e4;
const int K = 18;

int n,m;
vector<pair<int,int> > adj[N];
priority_queue<ti,vector<ti>,greater<ti> > q;
vector<ti> im,nm;
int pa[N];
int dp[K][N],mx[K][N],lv[N];
int ans = INT_MAX;

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

void dfs(int u,int p,int l,int ed)
{
    lv[u] = l,dp[0][u] = p,mx[0][u] = ed;
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i].second,w = adj[u][i].first;
        if(v!=p) dfs(v,u,l+1,w);
    }
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    int dist = 0;
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) dist = max(dist,mx[i][a]),a = dp[i][a];
    if(a==b) return dist;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) dist = max(dist,max(mx[i][a],mx[i][b])),a = dp[i][a],b = dp[i][b];
    dist = max(dist,max(mx[0][a],mx[0][b]));
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++) 
    {
        int a,b,d;
        cin >> a >> b >> d;
        q.push({d,a,b});
    }

    for(int i = 0;i < n;i++) pa[i] = i;

    while(!q.empty())
    {
        int d,a,b; tie(d,a,b) = q.top();
        q.pop();
        if(root(a)==root(b)) nm.push_back({d,a,b});
        else 
        {
            im.push_back({d,a,b});
            adj[a].push_back({d,b});
            adj[b].push_back({d,a});
            pa[root(a)] = root(b);
        }
    }

    dfs(0,0,1,0);

    for(int i = 1;i < K;i++) for(int j = 0;j < n;j++) dp[i][j] = dp[i-1][dp[i-1][j]],mx[i][j] = max(mx[i-1][dp[i-1][j]],mx[i-1][j]);

    for(int i = 0;i < nm.size();i++)
    {
        int a,b,d; tie(d,a,b) = nm[i];
        int dist = lca(a,b);
//        cout << a << ' ' << b << ' ' << d << ' ' << dist << endl;
        ans = min(ans,d-dist);
    }

    cout << ans+1;
}
