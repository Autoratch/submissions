#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

string t = " codecube",s;
int dp[N][9],st[N][9],ans = INT_MAX,be,en;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    for(int i = 0;i < s.length();i++) for(int j = 0;j <= 8;j++) st[i][j] = -1,dp[i][j] = INT_MAX;
    for(int i = 0;i < s.length();i++) for(int j = 1;j <= 8;j++)
    {
        if(s[i]==t[j])
        {
            if(j==1) st[i][j] = i+1,dp[i][j] = 0;
            else if(i>0 and st[i-1][j-1]!=-1) st[i][j] = st[i-1][j-1],dp[i][j] = dp[i-1][j-1];
        }
        else if(i>0 and st[i-1][j]!=-1) st[i][j] = st[i-1][j],dp[i][j] = dp[i-1][j]+1;
        if(j==8)
        {
            if(dp[i][j]<ans) ans = dp[i][j],be = st[i][j],en = i+1;
        }
    }
    if(be==0) cout << "-1";
    else cout << be << ' ' << en;
}
