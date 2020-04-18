#include "ricehub.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int l,r,ans;
long long s[N];

int besthub(int n,int m,int a[],long long k)
{
    s[0] = a[0];
    for(int i = 1;i < n;i++) s[i] = s[i-1]+a[i];
    while(r<n)
    {
        long long m = (l+r)/2;
        long long ll = s[m-1]-s[l-1],rr = s[r]-s[m];
        ll = (long long)a[m]*(m-l)-ll,rr-=(long long)a[m]*(r-m);
        if(ll+rr<=k) ans = max(ans,r-l+1),r++;
        else l++;
    }
    return ans;
}
