#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int N = 1e4;

int n,m,s,t;
vector<pii> adj[N];
int dist[N];
bool visited[N];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> t;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    for(int i = 0;i < n;i++) dist[i] = INT_MAX;
    dist[s] = 0;

    q.push({0,s});
    while(!q.empty())
    {
        int p = q.top().second;
        q.pop();
        for(int i = 0;i < adj[p].size();i++)
        {
            if(dist[p]+adj[p][i].first<dist[adj[p][i].second])
            {
                dist[adj[p][i].second] = dist[p]+adj[p][i].first;
                q.push({dist[adj[p][i].second],adj[p][i].second});
            }
        }
    }

    cout << dist[t];
}
