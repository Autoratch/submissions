#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const long long MOD = 998244353;

int n;
int ten[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    ten[0] = 1;
    for(int i = 1;i < N;i++) ten[i] = ((long long)ten[i-1]*10LL)%MOD;
    for(int i = 1;i <= n;i++)
    {
        if(i==n){ cout << "10"; return 0; }
        long long x = 18;
        if(i<n) x = (x*ten[n-i-1])%MOD;
        long long y = 81;
        if(i<n-1) y = (y*ten[n-i-2])%MOD;
        else y = 0;
        y = (y*(n-i-1))%MOD;
        cout << (10LL*(x+y))%MOD << ' ';
    }
}
