#include <bits/stdc++.h>
using namespace std;

const int N = 120;

int m,n,a,b;
string s[N];
bool visited[N][N][3][2];
queue<pair<pair<int,int>,pair<int,int> > > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++) cin >> s[i];
    
    for(int i = 0;i < n;i++)
    {
        if(s[m-1][i]!='$') continue;
        q.push({{m-1,i},{-1,0}});
        q.push({{m-1,i},{1,0}});
        visited[m-1][i][0][0] = true;
        visited[m-1][i][2][0] = true;
    }

    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,d = q.front().second.first,b = q.front().second.second;
        q.pop();
        for(int i = -1;i <= 0;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            if(x==0 and i==-1) continue;
            if(j!=0 and j!=d) continue;
            int ai = x+i,aj = y+j,ad = d,ab = b;
            if((y==0 and d==-1)or(y==n-1 and d==1)){ aj = y; ad = -d; }
            if(i==-1 and s[ai][aj]!='.')
            {
                if(b) continue;
                ab = 1;
            }
            if(s[ai][aj]=='@') continue;
            if(i!=-1 and s[ai][aj]=='.') continue;
            if(visited[ai][aj][ad+1][ab]) continue;
            visited[ai][aj][ad+1][ab] = true;
            q.push({{ai,aj},{ad,ab}});
        }
    }

    for(int i = 0;i < n;i++) 
    {
        if(visited[0][i][0][0]){ a++; b++; }
        else if(visited[0][i][0][1]) b++;
        if(visited[0][i][2][0]){ a++; b++; }
        else if(visited[0][i][2][1]) b++;
    }

    cout << a << ' ' << b;
}
