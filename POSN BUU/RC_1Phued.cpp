#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n,a[N],dp[N][2];
set<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        int ans = 0;
        for(int i = 1;i <= n;i++) cin >> a[i];
  //      q.clear();
        for(int i = 1;i <= n;i++)
        {
            if(a[i]>a[i-1]) dp[i][0] = dp[i-1][0]+1,dp[i][1] = dp[i-1][1]+1;
            else dp[i][0] = 1,dp[i][1] = 1;
//            auto it = q.upper_bound(make_pair(a[i],INT_MIN));
    //        it--;
      //      if(!q.empty()) dp[i][1] = max(dp[i][1],it->second+1);
        //    q.insert({a[i],dp[i][0]});
            for(int j = 1;j < i;j++) if(a[j]<a[i]) dp[i][1] = max(dp[i][1],dp[j][0]+1);
            ans = max(ans,max(dp[i][0],dp[i][1]));
        }
        cout << ans << '\n';
    }
}
