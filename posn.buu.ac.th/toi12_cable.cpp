#include <bits/stdc++.h>
using namespace std;

const int N = 2501;

int n,m,s,t,k,mn = INT_MAX;
vector<pair<int,int> > res[N];
int adj[N][N];
int dist[N],pa[N];
bool visited[N];

void dfs(int u,int p,int w)
{
    if(u==t) mn = w;
    for(int i = 0;i < res[u].size();i++) if(res[u][i].second!=p) dfs(res[u][i].second,u,min(w,res[u][i].first));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) adj[i][j] = INT_MIN;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a][b] = adj[b][a] = d;
    }

    for(int i = 2;i <= n;i++) dist[i] = INT_MIN;
    
    for(int i = 0;i < n;i++)
    {
        int each = INT_MIN,id;
        for(int j = 1;j <= n;j++) if(dist[j]!=-1 and dist[j]>each) each = dist[j],id = j;
        if(pa[id]) res[pa[id]].push_back({dist[id],id}),res[id].push_back({dist[id],pa[id]});
        dist[id] = -1;
        for(int j = 1;j <= n;j++) if(dist[j]!=-1 and adj[id][j]>dist[j]) dist[j] = adj[id][j],pa[j] = id;
    }

    cin >> s >> t >> k;

    dfs(s,0,INT_MAX);

    mn--;
    if(k%mn!=0) cout << k/mn+1;
    else cout << k/mn;
}
