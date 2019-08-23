#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

struct node
{
    int il,ir,val;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.il = a.il;
        ret.ir = b.ir;
        ret.val = max(a.val,b.val);
        return ret;
    }
};

int n,k,s,ix[N];
node tree[N << 1];
set<int> st;
vector<pair<int,int> > inp;

void build(int l,int r,int idx)
{
    if(l==r)
    {
        tree[idx].il = tree[idx].ir = ix[l];
        if(tree[idx].il==s) tree[idx].val = 0;
        else tree[idx].val = INT_MIN;
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,int k)
{
    if(tree[idx].il>x or tree[idx].ir<x) return;
    if(l==r) 
    {
        tree[idx].val = max(tree[idx].val,k);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,k),update(m+1,r,idx*2+1,x,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(tree[idx].il>y or tree[idx].ir<x)
    {
        node ret;
        ret.val = INT_MIN;
        return ret;
    }
    if(tree[idx].il>=x and tree[idx].ir<=y) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> s;

    inp.resize(n);
    st.insert(s);
    for(int i = 0;i < n;i++)
    {
        cin >> inp[i].first >> inp[i].second;
        st.insert(inp[i].first);
    }

    n = st.size();
    int idd = 0;
    for(auto it : st) ix[idd++] = it;

    build(0,n-1,1);

    for(pair<int,int> x : inp)
    {
        int id = x.first,va = x.second;
        int tmp = read(0,n-1,1,id-k,id+k).val;
        if(tmp==INT_MIN) continue;
        update(0,n-1,1,id,tmp+va);
    }

    cout << read(0,n-1,1,0,1e9).val;
}
