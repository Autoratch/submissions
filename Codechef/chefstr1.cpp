#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        long long ans = 0;
        for(int i = 2;i <= n;i++) ans+=max(abs(a[i-1]-a[i])-1,0);
        cout << ans << '\n';
    }
}
