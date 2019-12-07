#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,k,ans;
int a[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i],s[i] = s[i-1]+a[i];
    for(int i = 1;i+k-1 <= n;i++) ans = max(ans,s[i+k-1]-s[i-1]);
    cout << ans;
}
