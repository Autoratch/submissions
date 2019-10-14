#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

struct node
{
    int val;
    friend node operator+(const node &a,const node &b)
    {
        if(a.val>b.val) return a;
        else return b;
    }
};

int n,k;
node tree[N << 1];

void update(int l,int r,int idx,int x,int k)
{
    if(x>r or x<l) return;
    if(l==r){ tree[idx].val = k; return; }
    int m = (l+r)/2;
    update(l,m,idx*2,x,k),update(m+1,r,idx*2+1,x,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret = {0}; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int solve(int l,int r,int k)
{
    l = max(l,0),r = min(r,n-1);
    return read(0,n-1,1,l,r).val<=k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < k;i++)
    {
        int x,h;
        cin >> x >> h;
        int l = 0,r = n;
        while(l<r)
        {
            int m = (l+r+1)/2;
            if(solve(x-m,x-1,h) and solve(x+1,x+m,h)) l = m;
            else r = m-1;
        }
        update(0,n-1,1,x,h);
        cout << l << '\n';
    }
}
