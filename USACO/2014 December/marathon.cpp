#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n,q;
pair<int,int> a[N];

int dist(pair<int,int> x,pair<int,int> y){ return abs(x.first-y.first)+abs(x.second-y.second); }

struct node
{
    int sum,mx,dl,dr;
    pair<int,int> l,r;
    friend node operator+(const node &a,const node &b)
    {
        if(a.sum==-1) return b;
        if(b.sum==-1) return a;
        node ret;
        ret.sum = a.sum+b.sum;
        ret.mx = max(a.mx,b.mx);
        ret.l = a.l,ret.dl = a.dl;
        ret.r = b.r,ret.dr = b.dr;
        ret.mx = max(ret.mx,a.dr+b.dl-dist(a.r,b.l));
        return ret;
    }
}tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r) return void(tree[idx] = {dist(a[l],a[l+1]),0,dist(a[l],a[l+1]),dist(a[l],a[l+1]),a[l+1],a[l]});
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x)
{
    if(x<l or x>r) return;
    if(l==r) return void(tree[idx] = {dist(a[l],a[l+1]),0,dist(a[l],a[l+1]),dist(a[l],a[l+1]),a[l+1],a[l]});
    int m = (l+r)/2;
    update(l,m,idx*2,x),update(m+1,r,idx*2+1,x);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {-1,0,0,0,{0,0},{0,0}};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i].first >> a[i].second;
    build(1,n-1,1);
    while(q--)
    {
        char c;
        cin >> c;
        if(c=='U')
        {
            int b,x,y;
            cin >> b >> x >> y;
            a[b] = {x,y};
            update(1,n-1,1,b-1),update(1,n-1,1,b);
        }
        else
        {
            int x,y;
            cin >> x >> y;
            node res = read(1,n-1,1,x,y-1);
            cout << res.sum-res.mx << '\n';
        }
    }
}
