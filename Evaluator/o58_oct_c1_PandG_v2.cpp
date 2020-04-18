#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int t,m,n,k,w,sx,sy;
char c[N][N];
tuple<int,int,int> g[N];
queue<tuple<int,int,int> > q;
int mng[N][N];
bool visited[N][N];
bool visit[N][N][1001];

void ghost(int id)
{
    int t,x,y;
    tie(t,x,y) = g[id];
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) visited[i][j] = false;
    q.push({0,x,y});
    visited[x][y] = true;
    while(!q.empty())
    {
        int w,x,y;
        tie(w,x,y) = q.front();
        q.pop();
        mng[x][y] = min(mng[x][y],w+t);
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(visited[ai][aj]) continue;
            if(c[ai][aj]=='#') continue;
            visited[ai][aj] = true;
            q.push({w+1,ai,aj});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> m >> n >> k >> w >> sx >> sy;
        for(int i = 0;i < k;i++) 
        {
            int t,x,y;
            cin >> t >> x >> y;
            g[i] = {t,x,y};
        }
        for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) mng[i][j] = INT_MAX;
        for(int i = 0;i < m;i++) cin >> c[i];
        for(int i = 0;i < k;i++) ghost(i);
        for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) for(int k = 0;k <= w;k++) visit[i][j][k] = false;
        q.push({0,sx,sy});
        visit[sx][sy][0] = true;
        int ans = 0;
        while(!q.empty())
        {
            int w,x,y; tie(w,x,y) = q.front();
            q.pop();
            ans = max(ans,w);
            if(w==1000) continue;
            for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
            {
                if(i!=0 and j!=0) continue;
                int ai = x+i,aj = y+j;
                if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
                if(visit[ai][aj][w+1]) continue;
                if(c[ai][aj]=='#') continue;
                if(mng[ai][aj]<=w+1) continue;
                q.push({w+1,ai,aj});
                visit[ai][aj][w+1] = true;
            }
        }
        if(ans>=w) cout << "YES\n";
        else cout << "NO\n";
    }
}

