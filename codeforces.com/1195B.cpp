#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n,k;

    cin >> n >> k;

    long long x = (k+n)*2LL;

    long long b = 3LL,c = -x;

    long long ans = (-b+sqrt(b*b-4LL*c))/2LL;

    cout << n-ans;
}
