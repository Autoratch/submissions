#include <bits/stdc++.h>
using namespace std;

const int N = 601;

int n,q;
string a,b;
int dp[N][N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> a;

    while(q--)
    {
        cin >> b;
        ans = 0;
        for(int i = 1;i <= a.length();i++) for(int j = 1;j <= b.length();j++)
        {
            if(a[i-1]!=b[j-1]) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            else dp[i][j] = dp[i-1][j-1]+1;
            ans = max(ans,dp[i][j]);
//            cout << i << ' ' << j << ' ' << 
        }
        cout << ans << '\n';
    }
}
