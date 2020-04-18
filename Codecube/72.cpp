#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int m,n;
bool a[N][N],visited[N][N];
int lv[N*2+1];
queue<pair<pair<int,int>,int> > q;
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = m-1;i >= 0;i--) for(int j = 0;j < n;j++) cin >> a[i][j];

    q.push({{0,0},0});
    visited[0][0] = true;

    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,l = q.front().second;
        q.pop();
        lv[l]++;
        for(int i = 0;i <= 1;i++) for(int j = 0;j <= 1;j++)
        {
            if(i==j) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(a[ai][aj]) continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            q.push({{ai,aj},l+1});
        }
    }

    for(int i = 0;i <= m+n;i++) ans+=lv[i]*lv[i];

    cout << ans;
}
