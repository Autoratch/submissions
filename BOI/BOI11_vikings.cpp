#include <bits/stdc++.h>
using namespace std;

const int N = 700;

int m,n; 
char s[N][N];
bool ok[N][N],visited[N][N];
int tx,ty,sx,sy,vx,vy;
queue<pair<pair<int,int>,int> > q;
int vk[N][N];

void viking()
{
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) vk[i][j] = INT_MAX;
    q.push({{vx,vy},0});
    visited[vx][vy] = true;
    while(!q.empty())
    {
        auto [x,y] = q.front().first;
        int t = q.front().second;
        q.pop();
        vk[x][y] = t;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(visited[ai][aj]) continue;
            if(s[ai][aj]=='I') continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            q.push({{ai,aj},t+1});
        }
    }
}

bool dead(int a,int b,int t)
{
    int x = a,y = b;
    while(x>=0 and s[x][y]!='I') if(vk[x--][y]<=t) return false;
    x = a,y = b;
    while(x<m and s[x][y]!='I') if(vk[x++][y]<=t) return false;
    x = a,y = b;
    while(y>=0 and s[x][y]!='I') if(vk[x][y--]<=t) return false;
    x = a,y = b;
    while(y<n and s[x][y]!='I') if(vk[x][y++]<=t) return false;
    return true;
}

void solve()
{
    q.push({{sx,sy},0});
    ok[sx][sy] = visited[sx][sy] = true;
    while(!q.empty())
    {
        auto [x,y] = q.front().first;
        int t = q.front().second;
        q.pop();
        if(t and !dead(x,y,t)) continue;
        ok[x][y] = true;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(s[ai][aj]=='I') continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            q.push({{ai,aj},t+1});
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> s[i][j];
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(s[i][j]=='T') tx = i,ty = j;
        else if(s[i][j]=='Y') sx = i,sy  =j;
        else if(s[i][j]=='V') vx = i,vy = j;
    }
    viking();
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) visited[i][j] = false;
    solve();
    if(ok[tx][ty]) cout << "YES";
    else cout << "NO";
}
