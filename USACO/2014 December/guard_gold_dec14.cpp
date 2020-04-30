#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n,k,ans = -1;
int a[N],b[N],c[N];
int dp[1 << N],he[1 << N];
bool t[N];

int main()
{
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1;i < (1 << n);i++) dp[i] = -1;
    for(int i = 0;i < n;i++) dp[1 << i] = c[i],he[1 << i] = a[i];
    for(int i = 1;i < (1 << n);i++)
    {
        if(he[i]>=k) ans = max(ans,dp[i]);
        for(int j = 0;j < n;j++) if(!(i&(1 << j)) and b[j]<=dp[i])
        {
            dp[i+(1 << j)] = max(dp[i+(1 << j)],min(c[j],dp[i]-b[j]));
            he[i+(1 << j)] = he[i]+a[j];
        }
    }
    if(ans==-1) cout << "Mark is too tall";
    else cout << ans;
}
