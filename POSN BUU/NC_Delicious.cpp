#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
long long s[N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        long long x;
        cin >> x;
        s[i] = s[i-1]+x;
        for(int j = 0;j < i;j++) if(s[i]>s[j]) dp[i] = max(dp[i],dp[j]+1);
    }

    cout << dp[n];
}
