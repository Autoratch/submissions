#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int> >

const int N = 1001;

int n,m;
vector<pair<pair<int,int>,int> > adj[N];
int dist[N][2];
bool visited[N][2];
priority_queue<pii,vector<pii>,greater<pii> > q;
int di = INT_MAX;

int dijkstra(int x)
{
    int di = INT_MAX;
   
    for(int i = 1;i <= n;i++) dist[i][0] = dist[i][1] = INT_MAX,visited[i][0] = visited[i][1] = 0;
    dist[1][1] = 0;
    q.push({0,{1,1}});
    
    while(!q.empty())
    {
        int p = q.top().second.first,lv = q.top().second.second;
        q.pop();
        if(visited[p][lv]) continue;
        visited[p][lv] = true;
        if(p==n and lv==0) di = min(di,dist[p][lv]);
        for(int i = 0;i < adj[p].size();i++)
        {
            int w = adj[p][i].first.first,v = adj[p][i].first.second,l = adj[p][i].second;
            if(l>x) continue;
            if(dist[p][lv]+w<dist[v][!lv])
            {
                dist[v][!lv] = dist[p][lv]+w;
                q.push({dist[v][!lv],{v,!lv}});
            }
        }
    }
    return di;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({{d,b},i+1});
        adj[b].push_back({{d,a},i+1});
    }
   
    di = dijkstra(m);

    int l = 1,r = m;

    while(l<r)
    {
        int m = (l+r)/2;
        if(dijkstra(m)==di) r = m;
        else l = m+1;
    }

    cout << l << ' ' << di;
}
