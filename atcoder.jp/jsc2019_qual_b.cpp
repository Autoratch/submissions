#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
const int MOD = 1e9 + 7;

int n;
long long k;
int a[N];
long long fr[N],al[N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++) 
    {
        for(int j = 0;j < i;j++) if(a[j]>a[i]) fr[i]++;
        for(int j = 0;j < n;j++) if(a[j]>a[i]) al[i]++;
    }

    for(int i = 0;i < n;i++)
    {
        long long each = (fr[i]*k)%MOD;
        long long bf = ((k*(k-1LL))/2LL)%MOD;
        bf = (bf*al[i])%MOD;
        ans = ((each+bf)%MOD+ans)%MOD;
    }

    cout << ans;
}
