#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long,int> 

const int N = 1e5 + 1;

int n,m,s,t,u,v;
vector<pair<int,int> > adj[N];
long long dist[3][N],resu[N][2],resv[N][2];
bool visited[N],ins[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
long long ans = LLONG_MAX;
int deg1[N],deg2[N];

void dijk(int x,long long (&dist)[N])
{
    for(int i = 1;i <= n;i++) dist[i] = LLONG_MAX,visited[i] = false;
    dist[x] = 0;
    q.push({0,x});
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [w,v] : adj[u]) if(dist[u]+w<dist[v])
        {
            dist[v] = dist[u]+w;
            q.push({dist[v],v});
        }
    }
}

void pre1(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    for(auto [w,v] : adj[u]) if(dist[0][u]+w==dist[0][v]) deg1[v]++,pre1(v);
}

void pre2(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    ins[u] = true;
    for(auto [w,v] : adj[u]) if(dist[0][v]+w==dist[0][u]) deg2[v]++,pre2(v);
}

void run1(int u)
{   
    for(auto [w,v] : adj[u]) if(dist[0][u]+w==dist[0][v]) 
    {
        deg1[v]--;
        resu[v][0] = min(resu[v][0],resu[u][0]),resv[v][0] = min(resv[v][0],resv[u][0]);
        if(!deg1[v]) run1(v);
    }
}

void run2(int u)
{
    for(auto [w,v] : adj[u]) if(dist[0][v]+w==dist[0][u])
    {
        deg2[v]--;
        resu[v][1] = min(resu[v][1],resu[u][1]),resv[v][1] = min(resv[v][1],resv[u][1]);
        if(!deg2[v]) run2(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> t >> u >> v;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }
    dijk(s,dist[0]);
    dijk(u,dist[1]);
    dijk(v,dist[2]);
    for(int i = 1;i <= n;i++) visited[i] = false;
    pre1(s);
    for(int i = 1;i <= n;i++) visited[i] = false;
    pre2(t);
    for(int i = 1;i <= n;i++) resu[i][0] = resu[i][1] = dist[1][i],resv[i][0] = resv[i][1] = dist[2][i];
    run1(s);
    run2(t);
    for(int i = 1;i <= n;i++) if(ins[i])
    {
        ans = min(ans,resu[i][0]+resv[i][1]);
        ans = min(ans,resu[i][1]+resv[i][0]);
    }
    ans = min(ans,dist[1][v]);
    cout << ans;
}
