#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int> > 

const int N = 5e4 + 1;

int n,m,k;
vector<pair<int,int> > adj[N];
int dist[N][2];
bool visited[N][2];
int ea[N];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    for(int i = 0;i < k;i++)
    {
        int a,b;
        cin >> a >> b;
        ea[a] = max(ea[a],b);
    }

    for(int i = 1;i <= n;i++) dist[i][0] = dist[i][1] = INT_MAX;

    dist[n][0] = 0;
    q.push({0,{n,0}});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second.first,lv = q.top().second.second;
        q.pop();
        if(w>dist[p][lv]) continue;
        for(int i = 0;i < adj[p].size();i++)
        {
            int v = adj[p][i].second,w = adj[p][i].first;
            int dst = dist[p][lv]+w;
            if(dst<dist[v][lv]) dist[v][lv] = dst,q.push({dist[v][lv],{v,lv}});
            if(!lv and ea[v] and dst-ea[v]<dist[v][1]) dist[v][1] = dst-ea[v],q.push({dist[v][1],{v,1}});
        }
    }
    
    for(int i = 1;i < n;i++) if(dist[i][1]<=dist[i][0]) cout << "1\n"; else cout << "0\n";
}
