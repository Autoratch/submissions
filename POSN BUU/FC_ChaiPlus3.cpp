#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n;

    cin >> n;

    cout << ((n*(n+1))/2)%MOD;
}
