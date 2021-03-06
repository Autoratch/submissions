#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int m,n;
char a[N][N];

int cnt(int x,int y)
{
    int cnt = 0;
    for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
    {
        if(i==0 and j==0) continue;
        if(i!=0 and j!=0) continue;
        int ai = x+i,aj = y+j;
        if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
        if(a[ai][aj]=='*') cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    int am = 0,now = 0,idx,idy;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(a[i][j]=='.') continue;
        int tmp = cnt(i,j);
        am++;
        if(tmp==4 and now){ cout << "NO"; return 0; }
        if(tmp==3){ cout << "NO"; return 0; }
        if(tmp==4) idx = i,idy = j;
    }

    int cn = 0;
    int x = idx,y = idy;
    while(x>=0 and x<m and y>=0 and y<n and a[x][y]=='*') x--,cn++;
    cn--;
    x = idx,y = idy;
    while(x>=0 and x<m and y>=0 and y<n and a[x][y]=='*') x++,cn++;
    cn--;
    x = idx,y = idy;
    while(x>=0 and x<m and y>=0 and y<n and a[x][y]=='*') y--,cn++;
    cn--;
    x = idx,y = idy;
    while(x>=0 and x<m and y>=0 and y<n and a[x][y]=='*') y++,cn++;
    

    if(cn==am) cout << "YES";
    else cout << "NO";
}
