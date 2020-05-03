#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long x,y,l,r;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> l >> r;
        long long a = x|y;
        if(x==0 or y==0) a = 0;
        cout << a << '\n';
    }
}
