#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

int dp[2][N],ans;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    for(int i = 1;i <= s.length();i++) for(int j = 0;j+i <= s.length();j++) if(s[j]==s[i+j-1])
    {
        if(i==1) dp[1][j] = 1;
        else if(i==2) dp[0][j] = dp[1][j],dp[1][j] = i;
        else if(dp[0][j+1]==i-2 or dp[1][j+1]==i-2) dp[0][j] = dp[1][j],dp[1][j] = i;
        ans = max(ans,dp[1][j]);
    }
    cout << ans;
}
