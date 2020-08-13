#include "party.h"
#include <bits/stdc++.h>
using namespace std;

int query(int l,int r)
{
    vector<int> ret;
    for(int i = l;i <= r;i++) ret.push_back(i);
    ret = ask(ret);
    return ret.size();
}

int findUnusualGuest(int n,int m,int q) 
{
    int l,r;
    if(n<m and query(0,n-1)>n) l = 0,r = n-1;
    else if(n<m) l = n,r = n+m-1;
    else if(query(n,n+m-1)>m) l = n,r = n+m-1;
    else l = 0,r = n-1;
    while(l<r)
    {
        int m = (l+r+1)/2-1;
        if(query(l,m)!=m-l+1) r = m;
        else l = m+1;
    }
    return l;
}
