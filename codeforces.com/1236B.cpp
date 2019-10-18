#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long mul(long long n,long long x)
{
    if(n==0) return 1;
    if(n==1) return x;
    long long a = mul(n/2LL,x);
    a = (a*a)%MOD;
    if(n%2LL==1LL) a = (a*x)%MOD;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long x,y;

    cin >> x >> y;

    swap(x,y);

    cout << mul(y,mul(x,2)-1);
}
