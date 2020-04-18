#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n,q;
int a[N],tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx] = a[l]; return; }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = max(tree[idx*2],tree[idx*2+1]);
}

int read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return INT_MIN;
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return max(read(l,m,idx*2,x,y),read(m+1,r,idx*2+1,x,y));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    
    for(int i = 0;i < n;i++) cin >> a[i];

    build(0,n-1,1);

    for(int i = 0;i < q;i++)
    {
        int l,r;
        cin >> l >> r;
        cout << read(0,n-1,1,l,r) << '\n';
    }
}
