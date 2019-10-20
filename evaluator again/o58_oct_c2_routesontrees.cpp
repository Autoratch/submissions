#include <bits/stdc++.h>
using namespace std;
#define pi tuple<int,int,int>

const int N = 1e5 + 1;

int n,m,k;
vector<pair<int,int> > adj[N];
int dist[N][6];
bool visited[N][6];
priority_queue<pi,vector<pi>,greater<pi> > q;
int ans = INT_MAX;

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
    q.push({0,1,0});

    while(!q.empty())
    {
        int w,u,l; tie(w,u,l) = q.top();
        q.pop();
        if(visited[u][l]) continue;
        visited[u][l] = true;
        for(int i = 0;i < adj[u].size();i++)
        {
            int w = adj[u][i].first,v = adj[u][i].second;
            int nl = l,nw = dist[u][l];
            if(w<-100) nl++;
            if(nl>k) continue;
            if(w>0) nw+=w;
            if(nw<dist[v][nl])
            {
                dist[v][nl] = nw;
                q.push({dist[v][nl],v,nl});
            }
        }
    }

    for(int i = 0;i <= k;i++) ans = min(ans,dist[n][i]);

    if(ans==INT_MAX) ans = -1;
    cout << ans;
}
