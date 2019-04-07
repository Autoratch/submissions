#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<long long,int>,pair<int,int> >

const int N = 8e4 + 1;

int n,m,l,k;
long long ans = LLONG_MAX;
vector<pair<long long,int> > adj[N];
long long dist[N][9];
bool visited[N][9],sp[N];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> l >> k;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        long long d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
    }

    for(int i = 0;i < l;i++)
    {
        int a;
        cin >> a;
        sp[a] = true;
    }

    for(int i = 1;i <= n;i++) for(int j = 0;j <= k;j++) dist[i][j] = LLONG_MAX;

    dist[1][0] = 0;
    q.push({{0,0},{1,-1}});

    while(!q.empty())
    {
        int lv = q.top().first.second,p = q.top().second.first,lst = q.top().second.second;
        q.pop();
        if(visited[p][lv]) continue;
        visited[p][lv] = true;
        int nlv = lv,nlst = lst;
        if(sp[p] and lv<k and p!=lst){ nlv++; nlst = p; }
        for(int i = 0;i < adj[p].size();i++)
        {
            long long dst = adj[p][i].first/(1 << nlv);
            if(dist[p][lv]+dst<dist[adj[p][i].second][nlv])
            {
                dist[adj[p][i].second][nlv] = dist[p][lv]+dst;
                q.push({{dist[adj[p][i].second][nlv],nlv},{adj[p][i].second,nlst}});
            }
        }
    }

    for(int i = 0;i <= k;i++) ans = min(ans,dist[n][i]);

    cout << ans;
}
