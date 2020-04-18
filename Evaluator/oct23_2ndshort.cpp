#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int N = 1e4 + 1;

int n,m,s,e,ans = INT_MAX;
vector<pair<int,int> > adj[N],rev[N];
int dist[N];
bool visited[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
queue<int> q2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> e;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        rev[b].push_back({d,a});
    }

    for(int i = 1;i <= n;i++) dist[i] = INT_MAX;
    dist[s] = 0;
    q.push({0,s});

    while(!q.empty())
    {
        int p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(dist[p]+adj[p][i].first<dist[adj[p][i].second])
            {
                dist[adj[p][i].second] = dist[p]+adj[p][i].first;
                q.push({dist[adj[p][i].second],adj[p][i].second});
            }
        }
    }

    for(int i = 1;i <= n;i++) visited[i] = false;
    q2.push(e);
    visited[e] = true;
    while(!q2.empty())
    {
        int p = q2.front();
        q2.pop();
        for(int i = 0;i < rev[p].size();i++)
        {
            if(dist[rev[p][i].second]+rev[p][i].first>dist[p]) ans = min(ans,dist[rev[p][i].second]+rev[p][i].first-dist[p]);
            else 
            {
                if(visited[rev[p][i].second]) continue;
                visited[rev[p][i].second] = true;
                q2.push(rev[p][i].second);
            }
        }
    }

    cout << dist[e]+ans;
}
