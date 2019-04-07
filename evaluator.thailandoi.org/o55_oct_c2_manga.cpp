#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;

int n,m,k,l,r;
vector<int> dist;
vector<bool> visited;
vector<pair<int,pair<int,int> > > adj[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

bool solve(int x)
{
    visited.assign(n+1,false);
    dist.assign(n+1,INT_MAX);
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
            if(adj[p][i].first>x) continue;
            int v = adj[p][i].second.second;
            if(dist[p]+adj[p][i].second.first<dist[v])
            {
                dist[v] = dist[p]+adj[p][i].second.first;
                q.push({dist[v],v});
            }
        }
    }
    if(dist[n]<=k) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({i+1,{c,b}});
        adj[b].push_back({i+1,{c,a}});
    }

    l = 1; r = m;

    while(l<r)
    {
        int m = (l+r)/2;
        bool ok = solve(m);
        if(!ok) l = m+1;
        else r = m;
    }

    if(solve(l)) cout << l;
    else cout << "-1";
}
