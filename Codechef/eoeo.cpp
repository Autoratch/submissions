#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    long long s,ss;
    cin >> t;
    while(t--)
    {
        cin >> ss; s = ss;
        long long a = 1;
        while(s%2LL==0) a++,s/=2LL;
        cout << ss/(1LL << a) << '\n';
    }
}
