#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n,k;
int a[N][N];
deque<pair<int,int> > q;
bool used[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    q.push_back({0,0});
    used[0] = true;
    int x,mn = INT_MAX;
    for(int i = 0;i < n;i++) if(!used[i]) if(a[0][i]<mn) mn = a[0][i],x = i;
    q.push_back({x,a[0][x]});
    used[x] = true;

    while(q.size()!=n)
    {
        int x = q.front().first,lx = q.front().second;
        int y = q.back().first,ly = q.back().second;
        int nx,mx = INT_MAX,ny,my = INT_MAX;
        for(int i = 0;i < n;i++) if(!used[i])
        {
            if(a[x][i]<mx) mx = a[x][i],nx = i;
            if(a[y][i]<my) my = a[y][i],ny = i;
        }
        if(mx<my)
        {
            q.push_front({nx,(lx-mx+k)%k});
            used[nx] = true;
        }
        else
        {
            q.push_back({ny,(ly+my)%k});
            used[ny] = true;
        }
    }

    while(!q.empty()) cout << q.front().second << '\n',q.pop_front();
}
