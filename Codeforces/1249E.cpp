#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,k;
int a[N],b[N],dp[N][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 0;i < n-1;i++) cin >> a[i];
    for(int i = 0;i < n-1;i++) cin >> b[i];
    dp[0][1] = 1e9;
    for(int i = 1;i < n;i++)
    {
        dp[i][0] = min(dp[i-1][0],dp[i-1][1])+a[i-1];
        dp[i][1] = min(dp[i-1][1],dp[i-1][0]+k)+b[i-1];
    }
    for(int i = 0;i < n;i++) cout << min(dp[i][0],dp[i][1]) << ' ';
}

