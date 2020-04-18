#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n,k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;i++) cin >> a[i],a[i] = -a[i];
        sort(a+1,a+n+1);
        for(int i = 1;i <= n;i++) a[i] = -a[i];
        long long s = 0;
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            s+=a[i];
            if(s>=(long long)i*(long long)k) ans = i;
        }
        cout << ans << '\n';
    }
}
