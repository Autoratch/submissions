#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

int n,q,e;
long long z;
pair<int,int> a[N];
struct node{ long long am,val,left,right; }tree[N*20];
int root[N],cnt;

int clone(int x){ tree[++cnt] = tree[x]; return cnt; }

void build(int l,int r,int idx)
{
    cnt = max(cnt,idx);
    tree[idx] = {0,0,idx*2,idx*2+1};
    if(l==r) return;
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
}

int update(int l,int r,int idx,int x,int k)
{
    int now = clone(idx); 
    tree[now].val+=k,tree[now].am++;
    if(l==r) return now;
    int m = (l+r)/2;
    if(x<=m) tree[now].left = update(l,m,tree[idx].left,x,k);
    else tree[now].right = update(m+1,r,tree[idx].right,x,k);
    return now;
}

pair<int,long long> read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {0,0};
    if(x<=l and y>=r) return {tree[idx].am,tree[idx].val};
    int m = (l+r)/2;
    pair<int,int> a = read(l,m,tree[idx].left,x,y),b = read(m+1,r,tree[idx].right,x,y);
    return {a.first+b.first,a.second+b.second};
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> e;
    for(int i = 1;i <= n;i++) cin >> a[i].first,a[i].second = i;
    build(1,n,1),root[0] = 1;
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) root[i] =  update(1,n,root[i-1],a[i].second,a[i].first);
    while(q--)
    {
        long long x,y;
        cin >> x >> y;
        if(e) x^=z,y^=z;
        int l = 1,r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            if(read(1,n,root[m],x,y).first>=(y-x+1)/2) r = m;
            else l = m+1;
        }
        long long ls = read(1,n,root[l],x,y).second,rs = read(1,n,root[n],x,y).second-ls;
        cout << rs-ls << '\n';
        z =rs-ls;
    }
}
