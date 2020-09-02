#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int> > 

const int N = 501;

int m,n;
char c[N][N];
int dist[N][N];
bool visited[N][N];
priority_queue<pii,vector<pii>,greater<pii> > q;

int cost(pair<int,int> a,pair<int,int> b)
{
    int x = max(a.first,b.first),y = max(a.second,b.second);
    if(a.first-b.first==a.second-b.second) return (c[x][y]!='\\');
    else return (c[x][y]!='/');
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    if((m+n)%2){ cout << "NO SOLUTION"; return 0; }
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> c[i][j];
    for(int i = 0;i <= m;i++) for(int j = 0;j <= n;j++) dist[i][j] = INT_MAX;
    dist[0][0] = 0;
    q.push({0,{0,0}});
    while(!q.empty())
    {
        auto [x,y] = q.top().second;
        q.pop();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 or j==0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>m or aj<0 or aj>n) continue;
            if(dist[x][y]+cost({x,y},{ai,aj})<dist[ai][aj]) dist[ai][aj] = dist[x][y]+cost({x,y},{ai,aj}),q.push({dist[ai][aj],{ai,aj}});
        }
    }
    cout << dist[m][n];
}
