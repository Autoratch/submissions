#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int n;
long long x,a[N],dp[N][3],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;

    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        dp[i][0] = max(dp[i-1][0],0LL)+a[i];
        dp[i][1] = max(max(dp[i-1][1],dp[i-1][0]),0LL)+a[i]*x;
        dp[i][2] = max(max(max(dp[i-1][1],dp[i-1][0]),dp[i-1][2]),0LL)+a[i];
        ans = max(ans,max(max(dp[i][0],dp[i][1]),dp[i][2]));
    }

    cout << ans;
}
