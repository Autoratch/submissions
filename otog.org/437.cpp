#include <bits/stdc++.h>
using namespace std;

long long solve(long long a,long long b,long long c)
{
    if(b==0) return 1%c;
    if(b==1) return a%c;
    long long x = solve(a,b/2LL,c);
    x = x*x;
    x%=c;
    if(b%2==1) x*=a,x%=c;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long a,b,c;

    while(cin >> a >> b >> c)
    {
        cout << solve(a,b,c) << '\n';
    }
}
