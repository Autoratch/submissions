#include "traffic.h"
#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,pair<int,int> > > ans;

bool ask(int a,int b,int c,int d)
{
    return abs(a-c)+abs(b-d)!=traffic_query(a,b,c,d);
}

void answer()
{
    pair<int,int> a,b,c,d;
    a = ans[0].first,b = ans[0].second,c = {0,0},d = {0,0};
    if(ans.size()==2) c = ans[1].first,d = ans[1].second;
    traffic_report(a.first,a.second,b.first,b.second,c.first,c.second,d.first,d.second);
}

void solve(int xl,int yl,int xr,int yr)
{
    if(xr-xl==1 or yr-yl==1){ ans.push_back({{xl,yl},{xr,yr}}); return; }
    int xm = (xl+xr)/2,ym = (yl+yr)/2;
    if(ask(xl,yl,xm,ym)) solve(xl,yl,xm,ym);
    if(ask(xm,ym,xr,yr)) solve(xm,ym,xr,yr);
}

int main()
{
    int n,k;

    traffic_init(&n,&k);

    for(int i = 1;i <= n;i++){ if(ask(1,i,n,i)) solve(1,i,n,i); if(ans.size()==k) break; }

    for(int i = 1;i <= n;i++){ if(ask(i,1,i,n)) solve(i,1,i,n); if(ans.size()==k) break; }

    answer();
}
