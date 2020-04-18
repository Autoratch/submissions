#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,pair<int,int> >

const int N = 21;

int n,p,k,ans = INT_MAX;
int a[N][N];
map<pair<int,int>,vector<pair<int,int> > > m;
int dist[N][N][N];
bool visited[N][N][N];
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
        m[{a,b}].push_back({c,d});
    }

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) for(int l = 0;l <= k;l++) dist[i][j][l] = INT_MAX;

    dist[0][0][0] = 0;
    q.push({{0,0},{0,0}});

    while(!q.empty())
    {
        int l = q.top().first.second,x = q.top().second.first,y = q.top().second.second;
        q.pop();
        if(visited[x][y][l]) continue;
        visited[x][y][l] = true;
        if(x==n-1 and y==n-1) ans = min(ans,dist[x][y][l]);
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=n or aj<0 or aj>=n) continue;
            if(dist[x][y][l]+a[ai][aj]<dist[ai][aj][l])
            {
                dist[ai][aj][l] = dist[x][y][l]+a[ai][aj];
                q.push({{dist[ai][aj][l],l},{ai,aj}});
            }
        }
        if(l==k) continue;
        for(auto it : m[{x,y}])
        {
            if(dist[x][y][l]<dist[it.first][it.second][l+1])
            {
                dist[it.first][it.second][l+1] = dist[x][y][l];
                q.push({{dist[it.first][it.second][l+1],l+1},{it.first,it.second}});
            }
        }
    }

    cout << ans;
}
