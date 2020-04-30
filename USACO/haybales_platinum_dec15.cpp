#include <bits/stdc++.h>
using namespace std;
 
const int N = 1 << 18;

int n,q;
int a[N];
struct node
{ 
    long long mn,sum; 
    friend node operator+(const node &a,const node &b){ node ret; ret.mn = min(a.mn,b.mn),ret.sum = a.sum+b.sum; return ret; }
}tree[N << 1];
long long lazy[N << 1];

void pushlz(int l,int r,int idx)
{
    if(!lazy[idx]) return;
    tree[idx].sum+=lazy[idx]*(r-l+1),tree[idx].mn+=lazy[idx];
    if(l!=r) lazy[idx*2]+=lazy[idx],lazy[idx*2+1]+=lazy[idx];
    lazy[idx] = 0;
}

void build(int l,int r,int idx)
{
    if(l==r) return void(tree[idx] = {a[l],a[l]});
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,int y,long long k)
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
    update(l,m,idx*2,x,y,k),update(m+1,r,idx*2+1,x,y,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return {LLONG_MAX,0};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,n,1);
    while(q--)
    {
        char c;
        int x,y,k;
        cin >> c >> x >> y;
        if(c=='M') cout << read(1,n,1,x,y).mn << '\n';
        else if(c=='S') cout << read(1,n,1,x,y).sum << '\n';
        else cin >> k,update(1,n,1,x,y,k);
    }
}
