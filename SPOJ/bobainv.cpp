#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 1;

int n,q;
int a[N],dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
    {
        if(i<j and a[i]>a[j]) dp[i][j] = 1;
        dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    }
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << dp[r][r]-dp[l-1][r]-dp[r][l-1]+dp[l-1][l-1] << '\n';
    }
}
