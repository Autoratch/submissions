#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

struct node
{
    int a,b,c,d;
};

int m,q;
vector<node> inp;
long long tree[N << 1],lazy[N << 1];
set<int> s;
vector<long long> a;

void pushlz(int l,int r,int idx)
{
    if(lazy[idx]==0) return;
    tree[idx] = lazy[idx]*(a[r+1]-a[l]);
    if(l!=r)
    {
        lazy[idx*2] = lazy[idx];
        lazy[idx*2+1] = lazy[idx];
    }
    lazy[idx] = 0;
}

void update(int l,int r,int idx,int x,int y,long long k)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return;
    if(x<=l and y>=r) 
    {
        lazy[idx] = k;
        pushlz(l,r,idx);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y,k);
    update(m+1,r,idx*2+1,x,y,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

long long read(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> q;

    for(int i = 0;i < q;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c;
        if(!a){ cin >> d; inp.push_back({a,b,c,d}); }
        else inp.push_back({a,b,c});
        s.insert(b);
        s.insert(c);
    }
    s.insert(0);
    s.insert(m);

    for(int x : s) a.push_back(x);
    for(node x : inp)
    {
        x.b = lower_bound(a.begin(),a.end(),x.b)-a.begin();
        x.c = lower_bound(a.begin(),a.end(),x.c)-a.begin()-1;
        if(x.a) cout << read(0,a.size()-1,1,x.b,x.c) << '\n';
        else update(0,a.size()-1,1,x.b,x.c,x.d);
    }
}
