#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

int tc,n;
long long k;
string s,t;
long long dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> tc;
    while(tc--)
    {
        cin >> n >> k >> s;
        t.clear();
        while(k) t = (char)(k%10LL+'0')+t,k/=10LL;
        dp[0] = 1;
        for(int i = 1;i <= n;i++) dp[i] = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;;j++)
            {
                if(i-j+1<1) break;
                if(j>t.length()) break;
                if(j==t.length() and s.substr(i-j+1-1,j)>=t) break;
                dp[i] = (dp[i]+dp[i-j])%MOD;
            }
        }
        cout << dp[n] << '\n';
    }
}
