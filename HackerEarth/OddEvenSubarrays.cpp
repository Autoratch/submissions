#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;

int n,a[N],cur;
long long dp[N*2],ans;

int tb(int x){ return x+(int)2e5; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> a[i];

    dp[tb(0)] = 1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i]%2==0) cur++;
        else cur--;
        ans+=dp[tb(cur)];
        dp[tb(cur)]++;
    }

    cout << ans;
}
