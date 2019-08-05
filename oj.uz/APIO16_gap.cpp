#include "gap.h"
#include <bits/stdc++.h>
using namespace std;

vector<long long> a;

long long findGap(int t,int n)
{
    long long mn,mx,ans = 0;

    MinMax(0,1e18,&mn,&mx);

    if(t==1)
    {
        a.push_back(mn),a.push_back(mx);
        int l = 1,r = n-2;
        while(l<=r)
        {
            MinMax(mn+1,mx-1,&mn,&mx);
            a.push_back(mn),a.push_back(mx);
            l++,r--;
        }
    }        
    else
    {
        long long each = (mx-mn+n-2)/(n-1);
        ans = each;
        for(long long x = mn;x <= mx;x+=each+1)
        {
            long long xa,xb;
            MinMax(x,x+each,&xa,&xb);
            a.push_back(xa),a.push_back(xb);
        }
    }

    sort(a.begin(),a.end());

    for(int i = 0;i < a.size()-1;i++) ans = max(ans,a[i+1]-a[i]);

    return ans;
}
