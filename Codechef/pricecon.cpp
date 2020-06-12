#include <bits/stdc++.h>
using namespace std;

int t,n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        int ans = 0;
        cin >> n >> k;
        for(int i = 0;i < n;i++){ int x; cin >> x; ans+=max(0,x-k); }
        cout << ans << '\n';
    }
}
