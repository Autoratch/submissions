#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int m,n;
int a[N][N],dp[N][N][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) 
    {
        for(int k = 0;k < 3;k++) dp[i][j][0] = max(dp[i][j][0],max(dp[i-1][j][k],dp[i][j-1][k]));
        dp[i][j][1] = max(dp[i-1][j][0],dp[i][j-1][0])+a[i][j];
        dp[i][j][2] = max(dp[i-1][j][1],dp[i][j-1][1])+a[i][j];
    }

    cout << max(dp[m][n][0],max(dp[m][n][1],dp[m][n][2]));
}
