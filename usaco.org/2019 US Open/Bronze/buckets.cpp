#include <bits/stdc++.h>
using namespace std;

const int N = 10,n = 10,m = 10;

char a[N][N];
int dist[N][N];
int sx,sy,tx,ty;
queue<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("buckets.in","r",stdin);
    freopen("buckets.out","w",stdout);

    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++){ cin >> a[i][j]; if(a[i][j]=='B') sx = i,sy = j; else if(a[i][j]=='L') tx = i,ty = j; }
    
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) dist[i][j] = INT_MAX;
    
    dist[sx][sy] = 0;

    q.push({sx,sy});

    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            int ai = x+i,aj = y+j;
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(a[ai][aj]=='R') continue;
            if(dist[ai][aj]!=INT_MAX) continue;
            dist[ai][aj] = dist[x][y]+1;
            q.push({ai,aj});
        }
    }

    cout << dist[tx][ty]-1;
}
