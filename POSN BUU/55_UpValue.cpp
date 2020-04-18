#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;

int t,n,k;
int a[N],dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) 
        {
            int mx = 0;
            dp[i] = 0;
            for(int j = 1;j <= min(k,i);j++)
            {
                mx = max(mx,a[i-j+1]);
                dp[i] = max(dp[i],dp[i-j]+mx*j);
            }
//            cout << dp[i] << ' ';
        }
 //       cout << endl;
        cout << dp[n] << '\n';
    }
}
