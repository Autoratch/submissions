#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int m,n;
bool res[N][N];
string s[N];
queue<pair<int,int> > q;

bool ch(int x,int y)
{
    if(x<0 or x+1>=m or y<0 or y+1>=n) return false;
    if(s[x][y]=='#' or s[x+1][y]=='#' or s[x][y+1]=='#' or s[x+1][y+1]=='#') return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) cin >> s[i];

    for(int i = 0;i < n-1;i++)
    {
        if(ch(0,i)){ res[0][i] = 1; q.push({0,i}); }
    }

    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        if(x==m-2){ cout << "yes"; return 0; }
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(!ch(ai,aj)) continue;
            if(res[ai][aj]) continue;
            q.push({ai,aj});
            res[ai][aj] = true;
        }
    }

    cout << "no";
}
