#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,pair<int,int> > 

const int N = 50;

int m,n,sx,sy,tx,ty;
char a[N][N];
int th[N][N],dist[N][N];
bool visited[N][N];
priority_queue<pii,vector<pii>,greater<pii> > q;

void solve()
{
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(a[i][j]=='A') sx = i,sy = j; else if(a[i][j]=='B') tx = i,ty = j;
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) dist[i][j] = INT_MAX,th[i][j] = INT_MAX,visited[i][j] = 0;
    dist[sx][sy] = th[sx][sy] = 0;
    q.push({{0,0},{sx,sy}});
    while(!q.empty())
    {
        int x = q.top().second.first,y = q.top().second.second;
        q.pop();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(a[ai][aj]=='#') continue;
            if(visited[ai][aj]) continue;
            int nth = th[x][y];
            if(a[ai][aj]=='t') nth++;
            if(nth<th[ai][aj] or (nth==th[ai][aj] and dist[x][y]+1<dist[ai][aj]))
            {
                th[ai][aj] = nth;
                dist[ai][aj] = dist[x][y]+1;
                q.push({{th[ai][aj],dist[ai][aj]},{ai,aj}});
            }
        }
    }

    if(th[tx][ty]==INT_MAX) cout << "-1";
    else cout << th[tx][ty] << ' ' << dist[tx][ty];
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> m >> n)
    {
        for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];
        solve();
    }
}
