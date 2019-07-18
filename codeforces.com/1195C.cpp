#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
long long a[N],b[N],dp[N][2],mx[N][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 1;i <= n;i++) 
    {
        dp[i][0] = a[i]+mx[i-1][1];
        dp[i][1] = b[i]+mx[i-1][0];
        mx[i][0] = max(mx[i-1][0],dp[i][0]);
        mx[i][1] = max(mx[i-1][1],dp[i][1]);
    }

    cout << max(mx[n][0],mx[n][1]);
}
