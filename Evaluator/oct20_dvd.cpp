#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

struct node
{
    int mn,mx;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.mx = max(a.mx,b.mx);
        ret.mn = min(a.mn,b.mn);
        return ret;
    }
};

int n,k,a[N];
node tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r)
    {
        tree[idx].mx = tree[idx].mn = l;
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,int k)
{
    if(x<l or x>r) return;
    if(l==r){ tree[idx].mn = tree[idx].mx = k; return; }
    int m = (l+r)/2;
    update(l,m,idx*2,x,k);
    update(m+1,r,idx*2+1,x,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(y<l or x>r)
    {
        node ret;
        ret.mx = INT_MIN;
        ret.mn = INT_MAX;
        return ret;
    }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) a[i] = i;
    build(0,n-1,1);

    for(int i = 0;i < k;i++)
    {
        int t,l,r;
        cin >> t >> l >> r;
        if(!t)
        {
            update(0,n-1,1,l,a[r]);
            update(0,n-1,1,r,a[l]);
            swap(a[l],a[r]);
        }
        else
        {
            node res = read(0,n-1,1,l,r);
            if(res.mn==l and res.mx==r) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
