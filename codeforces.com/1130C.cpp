#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int n,sx,sy,ex,ey;
char a[N][N];
int s[N][N];
queue<pair<int,int> > q;
int ans = INT_MAX;

void bfs(int x,int y,int t)
{
    q.push({x,y});
    s[x][y] = t;

    while(!q.empty())
    {
        x = q.front().first,y = q.front().second;
        q.pop();
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=n or aj<0 or aj>=n) continue;
            if(s[ai][aj]) continue;
            if(a[ai][aj]=='1') continue;
            s[ai][aj] = t;
            q.push({ai,aj});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> sx >> sy >> ex >> ey;
    sx--,sy--,ex--,ey--;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> a[i][j];
    
    bfs(sx,sy,1);
    if(s[ex][ey]==1){ cout << "0"; return 0; }
    bfs(ex,ey,2);

    for(int a = 0;a < n;a++) for(int b = 0;b < n;b++) for(int c = 0;c < n;c++) for(int d = 0;d < n;d++) 
    {
        if(s[a][b]!=1 or s[c][d]!=2) continue;
        int x = (a-c)*(a-c),y = (b-d)*(b-d); 
        ans = min(ans,x+y);
    }
    
    cout << ans;
}
