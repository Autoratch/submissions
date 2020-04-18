#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int m,n,k;
char a[N][N];
bool visited[N][N];

void dfs(int x,int y)
{
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
    {
        int ai = x+i,aj = y+j;
        if(i==0 and j==0) continue;
        if(i!=0 and j!=0) continue;
        if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
        if(a[ai][aj]!='.') continue;
        dfs(ai,aj);
    }
    if(k) a[x][y] = 'X',k--;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(a[i][j]=='.')
        {
            dfs(i,j);
            for(int x = 0;x < m;x++){ for(int y = 0;y < n;y++) cout << a[x][y]; cout << '\n'; }
            return 0;
        }
    }
}
