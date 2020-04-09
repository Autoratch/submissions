#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

struct node
{
    int val,idx;
    friend node operator+(const node &a,const node &b)
    {
        if(a.val>b.val) return a;
        else if(a.val==b.val and a.idx>b.idx) return a;
        else return b;
    }
};

int n,qa,qb,q;
int a[N];
node tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].idx = l; return; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,int k)
{
    if(x<l or x>r) return;
    if(l==r){ tree[idx].val = k; return; }
    int m = (l+r)/2;
    update(l,m,idx*2,x,k),update(m+1,r,idx*2+1,x,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> qa >> qb;
    q = qa+qb;

    build(1,n,1);

    while(q--)
    {
        char c;
        cin >> c;
        if(c=='L')
        {
            int x,y;
            cin >> x >> y;
            a[y]++;
            update(1,n,1,y,a[y]);
        }
        else if(c=='C')
        {
            int x,y;
            cin >> x >> y;
            a[y]+=3;
            update(1,n,1,y,a[y]);
        }
        else if(c=='R') cout << tree[1].idx << '\n';
        else update(1,n,1,tree[1].idx,0);
    }
}
