#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

struct node
{
    int mx,idx;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        if(a.mx>b.mx or (a.mx==b.mx and a.idx>b.idx))
        {
            ret.mx = a.mx;
            ret.idx = a.idx;
        }
        else 
        {
            ret.mx = b.mx;
            ret.idx = b.idx;
        }
        return ret;
    }
};

int n,l,r;
node tree[N << 1];

void update(int l,int r,int idx,int x,int k)
{
    if(x<l or x>r) return;
    if(l==r)
    {
        tree[idx].mx+=k;
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,k);
    update(m+1,r,idx*2+1,x,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void build(int l,int r,int idx)
{
    if(l==r)
    {
        tree[idx].mx = 0;
        tree[idx].idx = l;
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l >> r;

    build(1,n,1);

    for(int i = 0;i < l+r;i++)
    {
        char c;
        cin >> c;
        if(c=='L')
        {
            int x,y;
            cin >> x >> y;
            update(1,n,1,y,1);
        }
        else if(c=='C')
        {
            int x,y;
            cin >> x >> y;
            update(1,n,1,y,3);
        }
        else if(c=='D') update(1,n,1,tree[1].idx,INT_MIN);            
        else cout << tree[1].idx << '\n';
    }
}
