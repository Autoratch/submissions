#include <bits/stdc++.h>
using namespace std;
#define pi tuple<int,int,int,int,int>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m,s;
    
    cin >> n >> m >> s;

    char cc[n+1][m+1];
    bool visited[n+1][m+1];

    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> cc[i][j];
    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) visited[i][j] = false;

    priority_queue<pi,vector<pi>,greater<pi> > q;

    q.push({0,s,1,s,0});

    while(!q.empty())
    {
        int w,a,b,c,d; tie(w,a,b,c,d) = q.top();
        q.pop();
        if(visited[a][b]) continue;
        visited[a][b] = true;
        if(b==m){ cout << w; return 0; }
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i!=0 and j!=0) continue;
            if(i==0 and j==0) continue;
            if(j<0) continue;
            if(a+i<1 or a+i>n or b+j<1 or b+j>m) continue;
            if(cc[a+i][b+j]=='#') continue;
            int p;
            if(a-c==i and b-d==j) p = w;
            else p = w+1;
            q.push({p,a+i,b+j,a,b});
        }
    }

    cout << "-1";
}
