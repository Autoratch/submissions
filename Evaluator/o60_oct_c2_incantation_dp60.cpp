#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int K = 1 << 7;

int n,k;
long long a[K],dp[N][K];
long long ans;

int main()
{
    cin >> n >> k;

    for(int i = 0;i < (1 << k);i++) cin >> a[i],dp[k][i] = a[i],ans = max(ans,a[i]);

    for(int i = k+1;i <= n;i++) for(int j = 0;j < (1 << k);j++)
    {
        dp[i][j] = a[j]+max(dp[i-1][j/2],dp[i-1][j/2+(1 << (k-1))]);
        ans = max(ans,dp[i][j]);
    }

    cout << ans;
}
