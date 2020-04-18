#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,a[N],dp[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        if(i<2) continue;
        for(int j = i-10;j <= i-3;j++) if(j>=0) dp[i] = max(dp[i],dp[j]);
        dp[i]+=a[i];
        ans = max(ans,dp[i]);
    }

    cout << ans;
}
