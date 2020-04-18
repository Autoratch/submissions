#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int> >

const int N = 5e4 + 1;
const int L = 31;

int n,m,l,s,e,lv[N];
vector<pair<int,int> > adj[N];
int dist[N][L];
bool visited[N][L];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> l >> s >> e;

    for(int i = 1;i <= n;i++) cin >> lv[i];

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
    }

    for(int i = 1;i <= n;i++) for(int j = 0;j <= l;j++) dist[i][j] = INT_MAX;

    q.push({0,{s,0}});
    dist[s][0] = 0;

    while(!q.empty())
    {
        int u = q.top().second.first,cl = q.top().second.second;
        q.pop();
        if(visited[u][cl]) continue;
        visited[u][cl] = true;
        for(int i = 0;i < adj[u].size();i++)
        {
            int w = adj[u][i].first,v = adj[u][i].second;
            if(lv[v]==cl+1)
            {
                if(dist[u][cl]+w<dist[v][cl+1])
                {
                    dist[v][cl+1] = dist[u][cl]+w;
                    q.push({dist[v][cl+1],{v,cl+1}});
                }
            }
            else
            {
                if(dist[u][cl]+w<dist[v][cl])
                {
                    dist[v][cl] = dist[u][cl]+w;
                    q.push({dist[v][cl],{v,cl}});
                }
            }
        }
    }

    cout << dist[e][lv[e]];
}
