#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5;

long long n,k,l = 1,r;
long long a[N];

long long solve(long long x)
{
    long long al = 0,ar = 0;
    long long l = x,r = x+k;
    for(long long i = 0;i < n;i++)
    {
        if(a[i]<l) al+=l-a[i];
        else if(a[i]>r) ar+=a[i]-r;
    }
    return max(al,ar);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(long long i = 0;i < n;i++) cin >> a[i],r = max(r,a[i]);
    r-=k;

    while(l<r)
    {
        long long m = (l+r)/2;
        long long x = solve(m);
        long long xl = solve(m-1);
        long long xr = solve(m+1);
        if(xl>=x and xr>=x){ cout << x; return 0; }
        if(xl<x) r = m-1;
        else if(xr<x) l = m+1;
    }

    cout << solve(l);
}
