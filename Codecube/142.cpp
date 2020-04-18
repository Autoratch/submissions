#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5;

long long n,w,k;
long long a[N],b[N];

long long solve(long long x)
{
    long long ans = 0LL;
    memset(b,0LL,sizeof b);
    for(long long i = 0;i < n;i++)
    {
        if(i) b[i]+=b[i-1];
        long long now = a[i]-x;
        if(now<=b[i]) continue;
        long long l = now-b[i];
        ans+=l;
        b[i]+=l;
        b[i+w]-=l;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> w >> k;
    for(long long i = 0;i < n;i++) cin >> a[i];

    long long l = 0LL,r = 1e9;
    while(l<r)
    {
        long long m = (l+r)/2LL;
        if(solve(m)<=k) r = m;
        else l = m+1LL;
    }

    cout << l;
}
