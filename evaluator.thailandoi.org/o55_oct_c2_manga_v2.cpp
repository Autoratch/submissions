#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 

const int N = 5e4 + 1;

int n,m,k;
vector<pair<int,pair<int,int> > > adj[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
int dist[N];
bool visited[N];

bool solve(int x)
{
    for(int i = 1;i <= n;i++) visited[i] = false,dist[i] = INT_MAX;
    dist[1] = 0;
    q.push({0,1});
    while(!q.empty())
    {
        int p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(adj[p][i].second.second>x) continue;
            if(dist[p]+adj[p][i].first<dist[adj[p][i].second.first])
            {
                dist[adj[p][i].second.first] = dist[p]+adj[p][i].first;
                q.push({dist[adj[p][i].second.first],adj[p][i].second.first});
            }
        }
    }
    return dist[n]<=k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,{b,i+1}});
        adj[b].push_back({d,{a,i+1}});
    }

    int l = 1,r = m+1;

    while(l<r)
    {
        int m = (l+r)/2;
        bool ok = solve(m);
        if(ok) r = m;
        else l = m+1;
    }

    if(l==m+1) cout << "-1";
    else cout << l;
}
