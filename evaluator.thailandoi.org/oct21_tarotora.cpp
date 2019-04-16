#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 100;
const int MAX = 2e9;

int t,n,k;
pair<int,int> a[N];
int dp[2][201];

int rtoi(int x){ return x+k; }
int itor(int x){ return x-k; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);   

    cin >> t;
    
    while(t--)
    {
        cin >> n >> k;
        for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
        for(int i = -k;i <= k;i++) dp[0][rtoi(i)] = MAX;
        dp[0][rtoi(0)] = 0;
        int prev = 0,cur = 1,ans = MAX;
        for(int i = 0;i < n;i++)
        {
            for(int j = -k;j <= k;j++) 
            {
                dp[cur][rtoi(j)] = MAX;
                if(j>-k) dp[cur][rtoi(j)] = min(dp[cur][rtoi(j)],dp[prev][rtoi(j)-1]+a[i].first);
                if(j<k) dp[cur][rtoi(j)] = min(dp[cur][rtoi(j)],dp[prev][rtoi(j)+1]+a[i].second);
            }
            swap(prev,cur);
        }
        for(int i = -k;i <= k;i++) ans = min(ans,dp[prev][rtoi(i)]);
        cout << ans << '\n';
    }
}
