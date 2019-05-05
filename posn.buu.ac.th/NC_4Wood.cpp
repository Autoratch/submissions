#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int MOD = 1e5 + 3;

int t,n;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    dp[0] = 1;
    for(int i = 1;i < N;i++)
    {
        dp[i] = dp[i-1]%MOD;
        if(i>=4) dp[i] = (dp[i]+dp[i-4])%MOD;
    }   

    while(t--)
    {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
}
