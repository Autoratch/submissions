#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n;
long long k,a[N],l,r;

bool solve(long long x)
{
    long long now = (x+1LL)*(x+1LL)*(long long)n;
    for(int i = 1;i < n;i++)
    {
        if(a[i-1]+x<a[i]-x) continue;
        long long t = a[i-1]+x-a[i]+x+1;
        if(t%2==1) now-=((t+1)/2)*((t+1)/2);
        else
        {
            t--;
            now-=((t+1)/2)*((t+1)/2);
            now-=x+1;
        }
    }
    return now>=k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);

    r = 1e9;

    while(l<r)
    {
        long long m = (l+r)/2LL;
        if(solve(m)) r = m;
        else l = m+1;
    }

    cout << l;
}
