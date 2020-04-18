#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

struct node
{
    int mx;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.mx = max(a.mx,b.mx);
        return ret;
    }
};

int n,m,k,ans;
node tree[N << 1];
int lazy[N << 1];

void pushlz(int l,int r,int idx)
{
    if(lazy[idx]==0) return;
    tree[idx].mx+=lazy[idx];
    if(l!=r) lazy[idx*2]+=lazy[idx],lazy[idx*2+1]+=lazy[idx];
    lazy[idx] = 0;
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
    update(l,m,idx*2,x,y,k),update(m+1,r,idx*2+1,x,y,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>r or y<l){ node ret; ret.mx = 0; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
       //         cout << read(1,n,1,a,b-1).mx << endl;
        if(read(1,n,1,a,b-1).mx>k-c) ans+=c;
        else update(1,n,1,a,b-1,c);
    }

    cout << ans;
}
