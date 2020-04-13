#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 1;
 
int t,n;
long long a[N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        long long mx = INT_MIN,dis = 0;
        for(int i = 1;i <= n;i++) mx = max(mx,a[i]),dis = max(dis,mx-a[i]);
        long long ans = 0,mul = 1;
        while(dis>0) dis-=mul,mul*=2LL,ans++;
        cout << ans << '\n';
    }
}
