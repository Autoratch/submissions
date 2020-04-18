#include <bits/stdc++.h>
using namespace std;

const int N = 300;

int m,n,sx,sy,tx,ty;
char a[N][N];
bool f[N][N][4],visited[N][N][4];
queue<pair<pair<int,int>,int> > q;
map<char,char> nxt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    nxt['|'] = '/';
    nxt['/'] = '-';
    nxt['-'] = '\\';
    nxt['\\'] = '|';

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) 
    {
        if(a[i][j]=='S') sx = i,sy = j;
        else if(a[i][j]=='E') tx = i,ty = j;
        if(a[i][j]=='.' or a[i][j]=='#' or a[i][j]=='S' or a[i][j]=='E') continue;
        char c = a[i][j];
        for(int k = 0;k < 4;k++)
        {
            int x = i,y = j;
            while(x>=0 and x<m and y>=0 and y<n)
            {
                if(a[x][y]=='#' or a[x][y]=='S' or a[x][y]=='E') break;
                if(a[x][y]!='.' and (x!=i or y!=j)) break;
                f[x][y][k] = true;
                if(c=='-') y--;
                else if(c=='/') x++,y--;
                else if(c=='|') x--;
                else x--,y--;
            }
            x = i,y = j;
            while(x>=0 and x<m and y>=0 and y<n)
            {
                if(a[x][y]=='#' or a[x][y]=='S' or a[x][y]=='E') break;
                if(a[x][y]!='.' and (x!=i or y!=j)) break;
                f[x][y][k] = true;
                if(c=='-') y++;
                else if(c=='/') x--,y++;
                else if(c=='|') x++;
                else x++,y++;
            }
            c = nxt[c];
        }
    }

    q.push({{sx,sy},0});

    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,l = q.front().second;
        q.pop();
        if(x==tx and y==ty){ cout << l; return 0; }
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(a[ai][aj]=='#') continue;
            if(f[ai][aj][(l+1)%4]) continue;
            if(visited[ai][aj][(l+1)%4]) continue;
            visited[ai][aj][(l+1)%4] = true;
            q.push({{ai,aj},l+1});
        }
    }

    cout << "-1";
}
