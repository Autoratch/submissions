#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,m,ans;
bool visited[N][N],en[N][N];
map<pair<int,int>,vector<pair<int,int> > > ma;
queue<pair<int,int> > q;

int main()
{
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ma[{a,b}].push_back({c,d});
    }

    en[1][1] = true;
    q.push({1,1});
    visited[1][1] = true;

    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        for(int ij = 0;ij < ma[{x,y}].size();ij++)
        {
            int ai = ma[{x,y}][ij].first,aj = ma[{x,y}][ij].second;
            if(en[ai][aj]) continue;
            en[ai][aj] = true;
            bool visit = false;
            for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
            {
                if(i==0 and j==0) continue;
                if(i!=0 and j!=0) continue;
                int xi = ai+i,xj = aj+j;
                if(xi<1 or xi>n or xj<1 or xj>n) continue;
                visit|=visited[xi][xj];
            }
            if(visit)
            {
                q.push({ai,aj});
                visited[ai][aj] = true;
            }
        }
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<1 or ai>n or aj<1 or aj>n) continue;
            if(visited[ai][aj]) continue;
            if(!en[ai][aj]) continue;
            q.push({ai,aj});
            visited[ai][aj] = true;
        }
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) ans+=en[i][j];

    cout << ans;
}
