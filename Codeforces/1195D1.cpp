#include <bits/stdc++.h>
using namespace std;

const long long N = 100000;
const long long K = 20;
long long MOD = 998244353LL;

long long n;
string a[N];
long long res[K];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 0;i < n;i++)
    {
        cin >> a[i];
        for(long long j = 0;j < a[i].length();j++) res[j*2]+=(a[i][j]-48LL)*(n);
        for(long long j = 0;j < a[i].length();j++) res[j*2+1]+=(a[i][j]-48LL)*(n);
   }

    for(long long i = 0;i < a[0].length()*2;i++) ans = ((ans*10LL)%MOD+res[i])%MOD;

    cout << ans;
}
