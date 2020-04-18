#include <bits/stdc++.h>
using namespace std;

const int N = 150001;

int t,n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        int ans = 0,mn = INT_MAX;
        for(int i = n-1;i >= 0;i--)
        {
            mn = min(mn,a[i]);
            if(mn<a[i]) ans++;
        }
        cout << ans << '\n';
    }
}