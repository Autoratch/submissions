#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 1;

int n,a[N],s[N],dp[2][N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i],s[i] = s[i+n] = a[i];
    int prev = 0,cur = 1;
    for(int i = 1;i <= n*2;i++)
    {
        for(int j = i+1;j <= n*2;j++) 
        {   
            if(s[i]!=s[j] or j==i+n){ dp[cur][j] = 0; continue; }
            dp[cur][j] = dp[prev][j-1]+1;
            ans = max(ans,dp[cur][j]);
        }
        swap(prev,cur);
    }
    for(int i = 1;i <= n;i++) s[i] = s[i+n] = a[n+1-i];
    for(int i = 1;i <= n*2;i++) dp[0][i] = dp[1][i] = 0;
    for(int i = 1;i <= n*2;i++)
    {
        for(int j = i+1;j <= n*2;j++) 
        {   
            if(s[i]!=s[j] or j==i+n){ dp[cur][j] = 0; continue; }
            dp[cur][j] = dp[prev][j-1]+1;
            ans = max(ans,dp[cur][j]);
        }
        swap(prev,cur);
    }
    if(ans>n) ans = -1;
    cout << ans; 
}
