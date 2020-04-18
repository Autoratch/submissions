#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

struct node
{
    int li,ri,val;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.li = a.li;
        ret.ri = b.ri;
        ret.val = a.val+b.val;
        return ret;
    }
};

int m,n;
int a[N];
node s[N << 1];
bool lazy[N << 1];
vector<int> in;
unordered_map<int,int> vtoi;

void pushlz(int l,int r,int idx)
{
    if(!lazy[idx]) return;
    lazy[idx] = false;
    s[idx].val = s[idx].ri-s[idx].li-s[idx].val;
    if(l!=r){ lazy[idx*2] = !lazy[idx*2]; lazy[idx*2+1] = !lazy[idx*2+1]; } 
}

void build(int l,int r,int idx)
{
    if(l==r)
    {
        s[idx].li = a[l-1];
        s[idx].ri = a[l];
        s[idx].val = s[idx].ri-s[idx].li;
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    s[idx] = s[idx*2]+s[idx*2+1];
}

void update(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return;
    if(x<=l and y>=r)
    {
        lazy[idx] = !lazy[idx];
        pushlz(l,r,idx);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y);
    update(m+1,r,idx*2+1,x,y);
    s[idx] = s[idx*2]+s[idx*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        a[i+1] = x;
        in.push_back(x);
    }

    a[n+1] = m;
    sort(a+1,a+n+1);

    build(1,n+1,1);

    for(int i = 1;i <= n;i++) vtoi[a[i]] = i;

    for(int i = 0;i < n;i++)
    {
        update(1,n+1,1,vtoi[in[i]]+1,n+1);
        cout << s[1].val << '\n';
    }
}
