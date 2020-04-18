#include <bits/stdc++.h>
using namespace std;
#define pii tuple<int,int,int>

const int N = 1000;

int n,m,s,t,scx,scy,sct,scd;
vector<pair<int,int> > adj[N];
int dist[N][2];
bool visited[N][2];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> t >> scx >> scy >> sct >> scd;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
    }
    for(int i = 0;i < n;i++) dist[i][0] = dist[i][1] = INT_MAX;
    dist[s][0] = 0;
    q.push({0,s,0});
    while(!q.empty())
    {
        auto [xx,p,used] = q.top();
        q.pop();
        if(visited[p][used]) continue;
        visited[p][used] = true;
        for(auto [w,v] : adj[p])
        {
            if(dist[p][used]+w<dist[v][used])
            {
                dist[v][used] = dist[p][used]+w;
                q.push({dist[v][used],v,used});
            }
        }
        if(p==scx and dist[p][used]<=scd and dist[p][used]+sct<dist[scy][1])
        {
            dist[scy][1] = dist[p][used]+sct;
            q.push({dist[scy][1],scy,1});
        }
    }
    cout << min(dist[t][0],dist[t][1]);
}