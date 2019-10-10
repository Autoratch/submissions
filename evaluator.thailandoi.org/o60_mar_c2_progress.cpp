#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n,m;
int a[N];

struct node
{
    int mxa,mxp,mxs,sum;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.sum = a.sum+b.sum;
        ret.mxp = max(a.mxp,a.sum+b.mxp);
        ret.mxs = max(b.mxs,b.sum+a.mxs);
        ret.mxa = max(max(a.mxa,b.mxa),a.mxs+b.mxp);
        return ret;
    }
}tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx] = {a[l],a[l],a[l],a[l]}; return; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,int y)
{
    if(x<l or x>r) return;
    if(l==r){ tree[idx] = {y,y,y,y}; return; }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y),update(m+1,r,idx*2+1,x,y);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i];

    build(0,n-1,1);

    cout << tree[1].mxa << '\n';
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        update(0,n-1,1,x,y);
        cout << tree[1].mxa << '\n';
    }
}
