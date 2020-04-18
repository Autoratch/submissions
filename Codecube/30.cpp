#include <bits/stdc++.h>
using namespace std;

const int N = 501;
const int K = 51;

int n,k,pre = 0,cur = 1;
int a[N][N],dp[2][N][K],mx[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];

    for(int i = 1;i <= n;i++)
    { 
        for(int j = 1;j <= n;j++) for(int l = 0;l <= k;l++)
        {
            if(l==0) dp[cur][j][l] = max(mx[i][j-1],mx[i-1][j]);
            else dp[cur][j][l] = a[i][j]+max(dp[cur][j-1][l-1],dp[pre][j][l-1]);
            mx[i][j] = max(mx[i][j],dp[cur][j][l]);
        }
        swap(pre,cur);
    }

    cout << mx[n][n];
}
