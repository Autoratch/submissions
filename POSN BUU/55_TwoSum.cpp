#include <bits/stdc++.h>
using namespace std;

int t,n;
map<int,long long> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        m.clear();
        long long ans = 0,a = 0;
        m[0] = 1;
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            a+=x;
            ans+=m[a];
            m[a]++;
        }
        cout << ans << '\n';
    }
}
