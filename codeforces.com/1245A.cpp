#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    while(n--)
    {
        int a,b;
        cin >> a >> b;
        if(__gcd(a,b)!=1) cout << "Infinite\n";
        else cout << "Finite\n";
    }
}