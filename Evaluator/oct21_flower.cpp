#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int m,n,ans;
int res[N][3],dp[N][N][N],no[N][N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < 3;j++) cin >> res[i][j];

    for(int i = 0;i <= m;i++) for(int j = 0;j < n;j++) for(int k = 0;k < n;k++) dp[i][j][k] = INT_MIN;
    dp[0][0][0] = 0;

    for(int i = 0;i < n;i++)
    {
        int c = res[i][0],v = res[i][1];
        bool hx = res[i][2],hy = 1-res[i][2];
        for(int k = 0;k <= m;k++) for(int x = 0;x < n;x++) for(int y = 0;y < n;y++)
        {
            no[k][x][y] = INT_MIN;
            if(k-c<0 or x-hx<0 or y-hy<0) continue;
            if(x>y and x>2*y+2) continue;
            if(y>x and y>2*x+2) continue;
            if(dp[k-c][x-hx][y-hy]<0) continue;
            no[k][x][y] = dp[k-c][x-hx][y-hy]+v;
            ans = max(ans,no[k][x][y]);
        }
        for(int k = 0;k <= m;k++) for(int x = 0;x < n;x++) for(int y = 0;y < n;y++) dp[k][x][y] = max(dp[k][x][y],no[k][x][y]);
    }

    cout << ans;
}
