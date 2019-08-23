#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

struct node
{
    int mxp,mxs,mxa,sum;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.mxp = max(a.mxp,a.sum+b.mxp);
        ret.mxs = max(b.mxs,b.sum+a.mxs);
        ret.mxa = max(max(a.mxa,b.mxa),a.mxs+b.mxp);
        ret.sum = a.sum+b.sum;
        return ret;
    }
};

int n,q;
int a[N];
node tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ node ret; ret.mxp = ret.mxs = ret.mxa = ret.sum = a[l]; tree[idx] = ret; return; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret; ret.mxp = ret.mxs = ret.mxa = ret.sum = 0; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 0;i < n;i++) cin >> a[i];

    build(0,n-1,1);

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << max(read(0,n-1,1,l,r).mxa,0) << '\n';
    }
}
