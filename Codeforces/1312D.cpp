#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int N = 2e5 + 1;

long long n,m,ans;
long long res[N],t[N];

long long powe(long long x,long long p)
{
    if(p==1) return x;
    long long t = powe(x,p/2LL);
    if(p%2==0) return (t*t)%MOD;
    else return ((t*t)%MOD*x)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    res[n-2] = t[0] = 1;
    for(long long i = n-1;i <= m;i++) res[i] = ((res[i-1]*(i))%MOD*powe(i-n+2LL,MOD-2))%MOD;
    for(int i = 1;i <= n;i++) t[i] = (t[i-1]*2LL)%MOD;
    for(long long x = n-1;x <= m;x++)
    {
        long long tmp;
        tmp = (res[x-1]*t[n-3])%MOD;
        tmp = (tmp*(n-2LL))%MOD;
        ans = (ans+tmp)%MOD;
    }
    cout << ans;
}
