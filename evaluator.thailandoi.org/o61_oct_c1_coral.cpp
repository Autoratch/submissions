#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

struct node
{
    bool fl,fr,fs,fa;
    friend node cal(node a,node b,node c)
    {
        node ret;
        ret.fl = c.fl|a.fs;
        ret.fr = c.fr|b.fs;
        ret.fs = c.fs|(a.fs&b.fs);
        ret.fa = c.fa|(a.fa&b.fa);
        return ret;
    };
};

node tree[N << 1];
int n,m;

void update(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return;
    if(x==l and y==r) 
    {
        if(tree[idx].fs) return;
        tree[idx].fs = true;
        if(l==r) tree[idx].fa = true;
        else
        {
            int m = (l+r)/2;
            if(tree[idx].fr) update(l,m,idx*2,l,m);
            else if(tree[idx].fl) update(m+1,r,idx*2+1,m+1,r);
            tree[idx] = cal(tree[idx*2],tree[idx*2+1],tree[idx]);
        }
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y);
    update(m+1,r,idx*2+1,x,y);
    tree[idx] = cal(tree[idx*2],tree[idx*2+1],tree[idx]); 
    if(tree[idx].fr and tree[idx].fs) update(l,m,idx*2,l,m);
    else if(tree[idx].fl and tree[idx].fs) update(m+1,r,idx*2+1,m+1,r);
    tree[idx] = cal(tree[idx*2],tree[idx*2+1],tree[idx]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    n = (1 << n);
    
    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        update(0,n-1,1,y,y+(1 << x)-1);
        if(tree[1].fa){ cout << i+1; return 0; }
    }
}
