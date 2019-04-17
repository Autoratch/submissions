#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int t,n,ans;
string s;
int dp[N][26][26];

int dist(int x,int y)
{
    return min(abs(x-y),26-abs(x-y));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;
        n = s.length();
        for(int i = 0;i < n;i++) for(int x = 0;x < 26;x++) for(int y = 0;y < 26;y++) dp[i][x][y] = INT_MAX;
        dp[0][0][s[0]-'A'] = dp[0][s[0]-'A'][0] = dist(s[0]-'A',0);
        if(n==1) ans = dp[0][0][s[0]-'A'];
        else ans = INT_MAX;
        for(int i = 1;i < n;i++)
        { 
            for(int x = 0;x < 26;x++) for(int y = 0;y < 26;y++)
            {
                if(dp[i-1][x][y]==INT_MAX) continue;
                dp[i][s[i]-'A'][y] = min(dp[i][s[i]-'A'][y],dist(s[i]-'A',x)+dp[i-1][x][y]);
                dp[i][x][s[i]-'A'] = min(dp[i][x][s[i]-'A'],dist(s[i]-'A',y)+dp[i-1][x][y]);
                if(i==n-1) ans = min(ans,dp[i][s[i]-'A'][y]),ans = min(ans,dp[i][x][s[i]-'A']);
            }
        }
        cout << ans << '\n';
    }
}
