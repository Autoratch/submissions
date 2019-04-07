#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> a(n+1);

    for(int i = 1;i <= n;i++){ cin >> a[i]; if(i) a[i]+=a[i-1]; }

    int ans = INT_MIN;

    for(int i = 1;i <= n;i++)
    {
        if(i+k>n+1) break;
        ans = max(ans,a[i+k-1]-a[i-1]);
    }

    cout << ans;
}
