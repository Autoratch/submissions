#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 101;

int n,k,p,ans;
int a[N],s[N];
int mx[N][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> p;

    for(int i = 1;i <= n;i++){ cin >> a[i]; s[i] = s[i-1]+a[i]; }
    
    int pre = 0,cur = 1;
    for(int j = 1;j <= k;j++)
    {
        for(int i = 1;i <= n;i++)
        {
            int dp;
            dp = s[i]-s[max(0,i-p)]+mx[max(0,i-p)][pre];
            mx[i][cur] = max(mx[i-1][cur],dp);
            ans = max(ans,dp);
        }
        swap(pre,cur);
    }

    cout << ans;
}
