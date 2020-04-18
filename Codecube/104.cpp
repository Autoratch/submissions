#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
const int K = 3001;
const int MAX = 1e9;

int n,a[N],dp[N][K],ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) dp[i][0] = MAX;
    for(int i = 1;i <= n;i++) for(int j = 1;j < K;j++)
    {
        if(a[i]==j) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = dp[i-1][j-1]+1;
        dp[i][j] = min(dp[i][j],dp[i][j-1]);
    }
    for(int i = 1;i < K;i++) ans = min(ans,dp[n][i]);
    cout << ans;
}
