#include "xylophone.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 5001;

int a[N],b[N],d[N],ans[N];

void solve(int n)
{
    for(int i = 1;i < n;i++) a[i] = query(i,i+1);
    for(int i = 1;i < n-1;i++) b[i] = query(i,i+2);
    int now = -1,cur = 1,mn = 1;
    for(int i = 1;i < n;i++) 
    {
        d[i] = now*a[i];
        if(b[i]==a[i] or b[i]==a[i+1]) now = -now;
        cur+=d[i];
        mn = min(mn,cur);
    }
    int st = 1+1-mn;
    for(int i = 1;i <= n;i++) ans[i] = st,st+=d[i];
    int lo,hi;
    for(int i = 1;i <= n;i++) if(ans[i]==1) lo = i; else if(ans[i]==n) hi = i;
    if(lo>hi) for(int i = 1;i <= n;i++) ans[i] = n+1-ans[i];
    for(int i = 1;i <= n;i++) answer(i,ans[i]);
}
