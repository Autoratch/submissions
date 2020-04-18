#include <bits/stdc++.h>
using namespace std;

long long n,s,mx;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        long long x;
        cin >> x;
        s+=x;
        mx = max(mx,x);
    }

    cout << max((s-1LL)/(n-1LL)+1LL,mx);
}
