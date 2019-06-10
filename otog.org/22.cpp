#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int m,n,sx,sy,tx,ty;
char a[N][N];
int s[N][N];
bool visited[N][N];
queue<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    cin >> sx >> sy >> tx >> ty;

    sx--,sy--,tx--,ty--;
    q.push({sx,sy});
    visited[sx][sy] = true;
    
    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        if(x==tx and y==ty){ cout << s[x][y]; return 0; }
        for(int i = -2;i <= 2;i++) for(int j = -2;j <= 2;j++)
        {
            if(i==0 or j==0) continue;
            if(abs(i)==abs(j)) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(a[ai][aj]=='X') continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            s[ai][aj] = s[x][y]+1;
            q.push({ai,aj});
        }
    }

    cout << "-1";
}
