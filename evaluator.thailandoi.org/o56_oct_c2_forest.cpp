#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,pair<int,int> >

const int N = 21;

int n,p,k,ans = INT_MAX;
int a[N][N];
int dist[N][N][N];
bool visited[N][N][N];
map<pair<int,int>,vector<pair<int,int> > > ma;
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> p >> k;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    for(int i = 0;i < p;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ma[{a,b}].push_back({c,d});
    }

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) for(int x = 0;x <= k;x++) dist[i][j][x] = INT_MAX;
    dist[0][0][0] = 0;
    q.push({{0,0},{0,0}});

    while(!q.empty())
    {
        int x = q.top().second.first,y = q.top().second.second,lv = q.top().first.second;
        q.pop();
        if(visited[x][y][lv]) continue;
        visited[x][y][lv] = true;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=n or aj<0 or aj>=n) continue;
            if(dist[x][y][lv]+a[ai][aj]<dist[ai][aj][lv])
            {
                dist[ai][aj][lv] = dist[x][y][lv]+a[ai][aj];
                q.push({{dist[ai][aj][lv],lv},{ai,aj}});
            }
        }
        if(lv==k) continue;
        for(int i = 0;i < ma[{x,y}].size();i++)
        {
            int ai = ma[{x,y}][i].first,aj = ma[{x,y}][i].second;
            if(dist[x][y][lv]<dist[ai][aj][lv+1])
            {
                dist[ai][aj][lv+1] = dist[x][y][lv];
                q.push({{dist[ai][aj][lv+1],lv+1},{ai,aj}});
            }
        }
    }

    for(int i = 0;i <= k;i++) ans = min(ans,dist[n-1][n-1][i]);

    cout << ans;
}
