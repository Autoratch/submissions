#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int n,a[N][N],dp[N][N],ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++) cin >> a[i][j];
    for(int i = 2;i < n;i++) for(int j = 1;j < i;j++)
    {
        dp[i][j] = INT_MAX;
        if(j+1<i or j==1) dp[i][j] = dp[i-1][j]+a[i-1][i];
        else for(int k = 1;k < j;k++) dp[i][j] = min(dp[i][j],dp[j][k]+a[k][i]);
    }
    for(int i = 1;i < n-1;i++) ans = min(ans,dp[n-1][i]+a[n-1][n]+a[i][n]);
    cout << ans;
}

