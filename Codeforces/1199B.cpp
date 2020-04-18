#include <bits/stdc++.h>
using namespace std;

double h,l;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> h >> l;

    cout << fixed;
    cout << setprecision(8) << ((l*l)/h-h)/2.0;
}
