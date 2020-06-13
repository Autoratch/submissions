#include "wall.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 21;

int val[N << 1],mn[N << 1],mx[N << 1];
int an[N];

void pushlz(int l,int r,int idx)
{
    if(l==r) val[idx] = max(val[idx],mn[idx]),val[idx] = min(val[idx],mx[idx]);
    else
    {
        mn[idx*2] = max(mn[idx*2],mn[idx]),mx[idx*2] = max(mx[idx*2],mn[idx]);
        mn[idx*2+1] = max(mn[idx*2+1],mn[idx]),mx[idx*2+1] = max(mx[idx*2+1],mn[idx]);
        mx[idx*2] = min(mx[idx*2],mx[idx]),mn[idx*2] = min(mn[idx*2],mx[idx]);
        mx[idx*2+1] = min(mx[idx*2+1],mx[idx]),mn[idx*2+1] = min(mn[idx*2+1],mx[idx]);
    }
    mn[idx] = INT_MIN,mx[idx] = INT_MAX;
}

void build(int l,int r,int idx)
{
    mn[idx] = INT_MIN,mx[idx] = INT_MAX;
    if(l==r) return;
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
}

void update(int l,int r,int idx,int t,int x,int y,int k)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return;
    if(x<=l and y>=r)
    {
        if(t==1) mn[idx] = k;
        else mx[idx] = k;
        pushlz(l,r,idx);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,t,x,y,k),update(m+1,r,idx*2+1,t,x,y,k);
}

void push(int l,int r,int idx)
{
    pushlz(l,r,idx);
    if(l==r) return void(an[l] = val[idx]);
    int m = (l+r)/2;
    push(l,m,idx*2),push(m+1,r,idx*2+1);
}

void buildWall(int n,int k,int o[],int l[],int r[],int h[],int ans[])
{   
    build(1,n,1);
    for(int i = 0;i < k;i++) update(1,n,1,o[i],l[i]+1,r[i]+1,h[i]);
    push(1,n,1);
    for(int i = 1;i <= n;i++) ans[i-1] = an[i];
}

