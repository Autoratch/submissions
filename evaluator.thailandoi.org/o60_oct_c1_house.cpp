#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

struct node
{
    int mxa,mxp,mxs,sum;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.mxa = max(max(a.mxa,b.mxa),a.mxs+b.mxp);
        ret.mxp = max(a.mxp,a.sum+b.mxp);
        ret.mxs = max(b.mxs,b.sum+a.mxs);
        ret.sum = a.sum+b.sum;
        return ret;
    }
};

int n,m;
int a[N];
node tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r)
    {
        node res;
        res.mxa = res.mxp = res.mxs = max(0,a[l]);
        res.sum = a[l];
        tree[idx] = res;
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    if(x>m) return read(m+1,r,idx*2+1,x,y);
    if(y<m+1) return read(l,m,idx*2,x,y);
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i];

    build(0,n-1,1);

    for(int i = 0;i < m;i++)
    {
        int l,r;
        cin >> l >> r;
        node res = read(0,n-1,1,l,r);
        cout << res.mxa << '\n';
    }
}
