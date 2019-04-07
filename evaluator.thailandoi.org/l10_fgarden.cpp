#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int m,n,ans;
char s[N][N];
bool visited[N][N];
queue<pair<int,int> > q;

void solve(int x,int y)
{
    int each = 0;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        each++;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(s[ai][aj]!='@') continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            q.push({ai,aj});
        }
    }
    ans = max(ans,each);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) cin >> s[i];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(s[i][j]=='#') continue;
        bool ok = true;
        for(int x = -1;x <= 1;x++) for(int y = -1;y <= 1;y++)
        {
            if(x==0 and y==0) continue;
            if(x!=0 and y!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(s[ai][aj]=='#') ok = false;
        }
        if(!ok) continue;
        s[i][j] = '@';
    }

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(!visited[i][j] and s[i][j]=='@') solve(i,j);
    }

    cout << ans;
}
