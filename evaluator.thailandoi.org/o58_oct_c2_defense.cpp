#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int n,k;
int a[N];
int dp[N][N];
int ans = INT_MAX;
deque<pair<int,int> > q[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++) if(!q[j].empty() and i-q[j].front().second>k) q[j].pop_front();
        for(int j = 0;j < i;j++)
        {
            dp[i][j] = INT_MAX;
            if(i<k and j<k) dp[i][j] = a[i]+a[j];
            if(!q[j].empty()) dp[i][j] = min(dp[i][j],q[j].front().first+a[i]);
//            for(int l = max(0,i-k);l < j;l++) dp[i][j] = min(dp[i][j],dp[j][l]+a[i]);
            while(!q[i].empty() and q[i].back().first>dp[i][j]) q[i].pop_back();
            if(dp[i][j]!=INT_MAX) q[i].push_back({dp[i][j],j});
            if(i>=n-k and j>=n-k) ans = min(ans,dp[i][j]);
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    cout << ans;
}
