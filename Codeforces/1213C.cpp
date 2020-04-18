#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        long long n,m,ans = 0;
        cin >> n >> m;
        n/=m;
        for(int i = 1;i <= 9;i++) 
        {
            long long tmp = n/10;
            if((n%10)>=i) tmp++;
            ans+=tmp*((i*(m%10))%10);
        }
        cout << ans << '\n';
    }
}