#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int p,m,k,mn = INT_MAX,ans;
int a[11],dp[N],lst[N],b[11],c[11],idx[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> p >> m >> k;
    for(int i = 1;i <= k;i++) cin >> a[i],idx[a[i]] = i;
    for(int i = 1;i <= m;i++) dp[i] = INT_MAX;
    for(int i = 1;i <= k;i++) for(int j = 1;j <= m;j++)
    {
        if(a[i]>j) continue;
        if(dp[j-a[i]]==INT_MAX) continue;
        if(dp[j-a[i]]+1<dp[j]) dp[j] = dp[j-a[i]]+1,lst[j] = j-a[i]; 
    }
    for(int i = p;i <= m;i++)
    {
        int ch = i-p;
        if(dp[ch]==INT_MAX or dp[i]==INT_MAX) continue;
        if(dp[ch]+dp[i]<mn) mn = dp[ch]+dp[i],ans = i;
    }
    for(int i = ans;i != 0;i = lst[i]) b[idx[i-lst[i]]]++;
    for(int i = ans-p;i != 0;i = lst[i]) c[idx[i-lst[i]]]++;
    cout << dp[ans] << ' ' << dp[ans-p] << '\n';
    for(int i = 1;i <= k;i++) cout << b[i] << ' ';
    cout << '\n';
    for(int i = 1;i <= k;i++) cout << c[i] << ' ';
}
