#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5;

long long n,a[N];

long long solve(long long l,long long r)
{
    if(l==r) return 0;
    long long m = (l+r)/2;
    long long ret = 0;
    ret+=solve(l,m)+solve(m+1,r);
    long long x[N],y[N];
    for(long long i = l;i <= m;i++) x[i-l] = a[i];
    for(long long i = m+1;i <= r;i++) y[i-m-1] = a[i];
    long long i = 0,j = 0,c = l;
    while(i<m-l+1 and j<r-m)
    {
        if(x[i]<=y[j])
        {
            a[c] = x[i];
            c++; i++;
        }
        else
        {
            a[c] = y[j];
            c++; j++;
            ret+=m-l+1-i;
        }
    }
    while(i<m-l+1){ a[c] = x[i]; c++; i++; }
    while(j<r-m){ a[c] = y[j]; c++; j++; }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 0;i < n;i++) cin >> a[i];

    cout << solve(0,n-1);
}
