#include <bits/stdc++.h>
using namespace std;

const int N = 80;

int m,n;
char a[N][N];
vector<pair<int,int> > u,d,l,r;

void solve(int x,int y,int ax,int ay)
{
    while(true)
    {
        x+=ax,y+=ay;
        if(x<0 or x>=m or y<0 or y>=n) return;
        else if(ax==0 and a[x][y]=='-') continue;
        else if(ax==0 and a[x][y]=='|') a[x][y] = '+';
        else if(ay==0 and a[x][y]=='|') continue;
        else if(ay==0 and a[x][y]=='-') a[x][y] = '+';
        else if(a[x][y]=='.'){ if(ax==0) a[x][y] = '-'; else a[x][y] = '|'; }
        else return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        cin >> a[i][j];
        if(a[i][j]=='B') a[i][j] = '*';
        else if(a[i][j]=='V') d.push_back({i,j});
        else if(a[i][j]=='^') u.push_back({i,j});
        else if(a[i][j]=='>') r.push_back({i,j});
        else if(a[i][j]=='<') l.push_back({i,j});
    }

    for(pair<int,int> s : u) solve(s.first,s.second,-1,0);
    for(pair<int,int> s : d) solve(s.first,s.second,1,0);
    for(pair<int,int> s : l) solve(s.first,s.second,0,-1);
    for(pair<int,int> s : r) solve(s.first,s.second,0,1);

    for(int i = 0;i < m;i++){ for(int j = 0;j < n;j++) cout << a[i][j]; cout << '\n'; }
}
