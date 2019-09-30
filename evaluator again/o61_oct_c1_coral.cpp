#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

int n,k,m;

struct node
{
    bool all,cur;
};

node tree[N << 1];

void update(int l,int r,int idx,int x,int y)
{
    if(tree[idx].all) return;
    if(x>r or y<l) return;
    int m = (l+r)/2;
    if(x==l and y==r)
    {
        if(tree[idx].cur) return;
        tree[idx].cur = true;
        if(l!=r and (tree[idx*2].cur or tree[idx*2+1].cur) and !(tree[idx*2].cur and tree[idx*2+1].cur))
        {
            if(tree[idx*2].cur) update(m+1,r,idx*2+1,m+1,r);
            else update(l,m,idx*2,l,m);
        }
        else if(l==r) tree[idx].all = true;
    }
    else if(l!=r)
    {
        update(l,m,idx*2,x,y);
        update(m+1,r,idx*2+1,x,y);
    }
    if(l==r) return;
    if(tree[idx*2].cur and tree[idx*2+1].cur) tree[idx].cur = true;
    if(tree[idx].cur and tree[idx*2].cur and !tree[idx*2+1].cur) update(m+1,r,idx*2+1,m+1,r);
    if(tree[idx].cur and tree[idx*2+1].cur and !tree[idx*2].cur) update(l,m,idx*2,l,m);
    if(tree[idx*2].all and tree[idx*2+1].all) tree[idx].all = true;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> m;
    n = 1 << k;

    for(int i = 1;i <= m;i++)
    {
        int a,b,l,r;
        cin >> a >> b;
        l = b,r = b+(1 << a)-1;
        update(0,n-1,1,l,r);
        if(tree[1].all){ cout << i; return 0; }
    }
}
