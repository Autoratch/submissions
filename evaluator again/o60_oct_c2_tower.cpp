#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

struct node
{
    int mx,am;
    bool pre,suf;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.mx = max(a.mx,b.mx);
        ret.pre = ret.suf = false;
        ret.am = 0;
        if(ret.mx==a.mx) ret.am+=a.am,ret.pre = a.pre;
        if(ret.mx==b.mx) ret.am+=b.am,ret.suf = b.suf;
        if(a.mx==b.mx and b.pre and a.suf) ret.am--;
        return ret;
    }
};

int n,m;
node tree[N << 1];
int lazy[N << 1];

void pushlz(int l,int r,int idx)
{
    if(!lazy[idx]) return;
    tree[idx].mx+=lazy[idx];
    if(l<r)
    {
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
    }
    lazy[idx] = 0;
}

void build(int l,int r,int idx)
{
    if(l==r)
    {
        tree[idx].mx = 0;
        tree[idx].am = 1;
        tree[idx].pre = tree[idx].suf = true;
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,int y,int k)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return;
    if(x<=l and y>=r)
    {
        lazy[idx]+=k;
        pushlz(l,r,idx);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y,k);
    update(m+1,r,idx*2+1,x,y,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    build(1,n,1);

    for(int i = 0;i < m;i++)
    {
        int a,b,x;
        cin >> a >> b >> x;
        update(1,n,1,a,b,x);
        pushlz(1,n,1);
        cout << tree[1].mx << ' ' << tree[1].am << '\n';
    }
}
