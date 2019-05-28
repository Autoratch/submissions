#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int n;
long long dp[N][N],sum[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) for(int j = i;j <= n;j++)
    {
        if(i==j) dp[i][j] = 1LL;
        else dp[i][j] = sum[j-i]-dp[i][j-i];
        sum[j]+=dp[i][j];
    }

    cout << sum[n]-1LL;
}
