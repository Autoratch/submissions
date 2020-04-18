#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int> >

const int N = 1e5 + 1;

int n,m,k,ans = INT_MAX;
vector<pair<int,int> > adj[N];
int dist[N][6];
bool visited[N][6];
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
    }

    for(int i = 1;i <= n;i++) for(int j = 0;j <= k;j++) dist[i][j] = INT_MAX;

    dist[1][0] = 0;
    q.push({0,{1,0}});

    while(!q.empty())
    {
        int p = q.top().second.first,h = q.top().second.second;
        q.pop();
        if(visited[p][h]) continue;
        visited[p][h] = true;
        for(int i = 0;i < adj[p].size();i++)
        {
            int v = adj[p][i].second,w = adj[p][i].first;
            if(w<-100)
            {
                w = 0;
                if(h<k and dist[p][h]+w<dist[v][h+1])
                {
                    dist[v][h+1] = dist[p][h]+w;
                    q.push({dist[v][h+1],{v,h+1}});
                }
            }
            else
            {
                w = max(w,0);
                if(dist[p][h]+w<dist[v][h])
                {
                    dist[v][h] = dist[p][h]+w;
                    q.push({dist[v][h],{v,h}});
                }
            }
        }
    }

    for(int i = 0;i <= k;i++) ans = min(ans,dist[n][i]);

    if(ans==INT_MAX) ans = -1;
    cout << ans;
}
