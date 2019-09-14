#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    
    cin >> n;

    int a[n];

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);
    
    int ans = INT_MAX;

    for(int i = 0;i < n-1;i++) ans = min(ans,a[i+1]-a[i]);

    cout << ans;
}
