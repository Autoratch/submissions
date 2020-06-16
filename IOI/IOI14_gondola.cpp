#include "gondola.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
const long long MOD = 1e9 + 9;

int repl[N];

int valid(int n,int a[])
{
    int x,y = 0;
    for(int i = 0;i < n;i++) if(a[i]<=n) x = i,y = a[i];
    for(int i = 0;i < n;i++) if(a[i]<=n)
    {
        int z = y+i-x;
        if(z>n) z%=n;
        if(z<1) z+=n;
        if(y and z!=a[i]) return 0;
    }
    sort(a,a+n);
    for(int i = 0;i < n-1;i++) if(a[i]==a[i+1]) return 0;
    return 1;
}

int replacement(int n,int a[],int ans[])
{
    int x = 0,y = 1,mx = 0;
    for(int i = 0;i < n;i++) 
    {
        if(a[i]<=n) x = i,y = a[i];
        mx = max(mx,a[i]);
    }
    int ret = mx-n;
    int bx = mx;
    for(int i = 0;i < n;i++)
    {
        int z = y+i-x;
        if(z>n) z%=n;
        if(z<1) z+=n;
        if(z!=a[i]) repl[a[i]] = z;
    }
    for(int i = 0;i < ret;i++)
    {
        int j = i+n+1;
        if(!repl[j]) repl[j] = repl[bx],repl[bx] = j;
        ans[i] = repl[j];
    }
    return ret;
}

long long poww(long long x,int y)
{
    if(y==0) return 1;
    if(y==1) return x%MOD;
    long long tmp = poww(x,y/2)%MOD;
    tmp = (tmp*tmp)%MOD;
    if(y%2==0) return tmp;
    return (tmp*x)%MOD;
}

int countReplacement(int n,int a[])
{
    int x = 0,y = 0,mx = 0;
    for(int i = 0;i < n;i++) 
    {
        if(a[i]<=n) x = i,y = a[i];
        mx = max(mx,a[i]);
    }
    bool oh = false;
    if(!y) oh = true;
    for(int i = 0;i < n;i++)
    {
        int z = y+i-x;
        if(z>n) z%=n;
        if(z<1) z+=n;
        if(!oh and z!=a[i] and a[i]<=n) return 0;
    }
    sort(a,a+n);
    for(int i = 0;i < n-1;i++) if(a[i]==a[i+1]) return 0;
    long long res = 1;
    for(int i = -1;i < n;i++)
    {
        int l,r;
        if(i>=0) l = a[i]+1;
        else l = n+1;
        if(i<n) r = a[i+1]-1;
        else r = mx;
        l = max(l,n+1);
        if(l>r) continue;
        res = (res*poww(n-1-i,r-l+1))%MOD;
    }
    if(oh) res = (res*n)%MOD;
    int ans = res;
    return ans;
}
