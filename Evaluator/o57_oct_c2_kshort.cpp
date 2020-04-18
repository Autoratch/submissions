#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int> >

const int N = 1e4 + 1;
const int L = 51;

int n,m,s,l,ans = INT_MAX;
vector<pair<int,int> > adj[N],ads[N];
int dist[N][L];
bool visited[N][L];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> l;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
    }

    for(int i = 0;i < s;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        ads[a].push_back({d,b});
    }

    for(int i = 1;i <= n;i++) for(int j = 0;j <= l;j++) dist[i][j] = INT_MAX;

    q.push({0,{1,0}});
    dist[1][0] = 0;

    while(!q.empty())
    {
        int p = q.top().second.first,lv = q.top().second.second;
        q.pop();
        for(int i = 0;i < adj[p].size();i++)
        {
            if(dist[p][lv]+adj[p][i].first<dist[adj[p][i].second][lv])
            {
                dist[adj[p][i].second][lv] = dist[p][lv]+adj[p][i].first;
                q.push({dist[adj[p][i].second][lv],{adj[p][i].second,lv}});
            }
        }
        if(lv==l) continue;
        for(int i = 0;i < ads[p].size();i++)
        {
            if(dist[p][lv]+ads[p][i].first<dist[ads[p][i].second][lv+1])
            {
                dist[ads[p][i].second][lv+1] = dist[p][lv]+ads[p][i].first;
                q.push({dist[ads[p][i].second][lv+1],{ads[p][i].second,lv+1}});
            }
        }
    }

    for(int i = 0;i <= l;i++) ans = min(ans,dist[n][i]);
   
    cout << ans;
}
