#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int K = 1401;

int m,n;
int a[N][N],dp[K][N][N],b2[N][N],b3[N][N];
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        while(a[i][j]%2==0) b2[i][j]++,a[i][j]/=2;
        while(a[i][j]%3==0) b3[i][j]++,a[i][j]/=3;
    }
    for(int i = 1;i < K;i++) for(int x = 1;x < N;x++) dp[i][x][0] = dp[i][0][x] = INT_MIN;
    for(int i = 0;i < K;i++) for(int x = 1;x <= m;x++) for(int y = 1;y <= n;y++)
    {
        if(b2[x][y]>i) continue;
        dp[i][x][y] = max(dp[i-b2[x][y]][x-1][y],dp[i-b2[x][y]][x][y-1])+b3[x][y];
    }
    for(int i = 1;i < K;i++) ans = max(ans,min(i,dp[i][m][n]));
    cout << ans;
}
