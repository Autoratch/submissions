#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int m,n;
char a[N][N];
bool visited[N][N];
string ans;
set<int> s,t;

void dfs(int x,int y)
{
    if(visited[x][y]) return;
    visited[x][y] = true;
    bool havelo = false,haveri = false;
    for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
    {
        if(i==0 and j==0) continue;
        if(i!=0 and j!=0) continue;
        int ai = x+i,aj = y+j;
        if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
        if(a[ai][aj]=='.') continue;
        if(i==1) havelo = true;
        if(j==1) haveri = true;
        dfs(ai,aj);
    }
    if(!havelo) s.insert(x);
    if(!haveri) t.insert(y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(a[i][j]=='.') continue;
        if(visited[i][j]) continue;
        s.clear();
        t.clear();
        dfs(i,j);
        if(s.size()==2) ans+='O';
        else if(t.size()==3) ans+='F';
        else ans+='P';
    }

    sort(ans.begin(),ans.end());
    if(ans.length()==0) ans+='N';

    cout << ans;
}
