#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

struct node
{
    int r,g,b;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.r = a.r+b.r;
        ret.g = a.g+b.g;
        ret.b = a.b+b.b;
        return ret;
    }
};

int n,m;
node tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r)
    {
        int r = 0,g = 0,b = 0;
        if(l%3==1) r++;
        else if(l%3==2) g++;
        else b++;
        tree[idx] = {r,g,b};
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,char c)
{
    if(x<l or x>r) return;
    if(l==r)
    {
        int r = 0,g = 0,b = 0;
        if(c=='R') r++;
        else if(c=='G') g++;
        else b++;
        tree[idx] = {r,g,b};
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,c);
    update(m+1,r,idx*2+1,x,c);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret = {0,0,0}; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    build(1,n,1);

    for(int i = 0;i < m;i++)
    {
        int t,a,b;
        char c;
        cin >> t;
        if(t==1)
        {
            cin >> a >> c;
            update(1,n,1,a,c);
        }
        else
        {
            cin >> a >> b;
            node res = read(1,n,1,a,b);
            if(res.r>res.b and res.r>res.g) cout << "R";
            else if(res.b>res.r and res.b>res.g) cout << "B";
            else if(res.g>res.r and res.g>res.b) cout << "G";
            else cout << "None";
            cout << '\n';
        }
    }
}
