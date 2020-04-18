#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 1;

int l,n,m;
int a[N],b[N];
int dp[2][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> l >> n >> m;

    int lst = 0;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        a[i] = x-lst;
        lst = x;
    }
    a[n] = l-lst;

    for(int i = 1;i <= m;i++) cin >> b[i];

    int prev = 0,cur = 1;

    for(int i = 2;i <= m;i++) dp[prev][i] = INT_MIN;

    for(int i = 0;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            dp[cur][j] = a[i]*b[j];
            if(i) dp[cur][j]+=max(dp[prev][j],dp[prev][j-1]);
            if(!i and j!=1) dp[cur][j] = INT_MIN;
//            cout << i << ' ' << j << ' ' << dp[cur][j] << endl;
        }
        swap(prev,cur);
    }

    cout << dp[prev][m];
}
