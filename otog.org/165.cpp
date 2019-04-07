#include <bits/stdc++.h>
using namespace std;

int cur = 1,pre = 0;
int dp[2][2][2]; // idx caps shft
string s;

bool caps(char c)
{
    if(c>='A' and c<='Z') return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    if(caps(s[0]))
    {
        dp[pre][1][0] = 1;
        dp[pre][0][1] = 1;
        dp[pre][0][0] = INT_MAX;
        dp[pre][1][1] = INT_MAX;
    }
    else 
    {
        dp[pre][0][0] = 0;
        dp[pre][1][1] = 2;
        dp[pre][0][1] = INT_MAX;
        dp[pre][1][0] = INT_MAX;
    }

    for(int cn = 2;cn <= s.length();cn++)
    {
        for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) dp[cur][i][j] = INT_MAX;
        if(caps(s[cn-1]))
        {
            dp[cur][1][0] = min(min(dp[pre][1][0],dp[pre][1][1]),min(dp[pre][0][0],dp[pre][0][1])+1);
            dp[cur][0][1] = min(min(dp[pre][0][0],dp[pre][0][1])+1,min(dp[pre][1][0],dp[pre][1][1])+2);
        }
        else
        {
            dp[cur][0][0] = min(min(dp[pre][0][0],dp[pre][0][1]),min(dp[pre][1][0],dp[pre][1][1])+1);
            dp[cur][1][1] = min(min(dp[pre][1][0],dp[pre][1][1])+1,min(dp[pre][0][0],dp[pre][0][1])+2);
        }
        swap(cur,pre);
    }

    int ans = INT_MAX;

    for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) ans = min(ans,dp[pre][i][j]);

    cout << ans;
}
