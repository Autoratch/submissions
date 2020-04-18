#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n,k,q;
int a[N];
pair<int,int> res[N];
struct node
{
    int val,num,left,right;
    friend node operator+(const node &a,const node &b)
    {
        node ret = {a.val+b.val,a.num+b.num,0,0};
        return ret;
    }
}tree[N*10];
int cnt,root[N];

int clone(int x){ tree[++cnt] = tree[x]; return cnt; }

void build(int l,int r,int idx)
{
    cnt = max(cnt,idx);
    if(l==r) return;
    int m = (l+r)/2;
    tree[idx].left = idx*2,tree[idx].right = idx*2+1;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
}

int update(int l,int r,int idx,int x)
{
    int now = clone(idx);
    tree[now].val+=a[x],tree[now].num++;
    if(l==r) return now;
    int m = (l+r)/2;
    if(x<=m) tree[now].left = update(l,m,tree[now].left,x);
    else tree[now].right = update(m+1,r,tree[now].right,x);
    return now;
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {0,0,0,0};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,tree[idx].left,x,y)+read(m+1,r,tree[idx].right,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> q;
    for(int i = 1;i <= n;i++) cin >> a[i],res[i] = {a[i],i};
    build(1,n,1);
    root[0] = 1;
    sort(res+1,res+n+1);
    for(int i = 1;i <= n;i++) root[i] = update(1,n,root[i-1],res[i].second);
    while(q--)
    {
        int x;
        cin >> x;
        int l = 0,r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            node tmp = read(1,n,root[m],1,x);
            if(tmp.num+k>=x) r = m;
            else l = m+1;
        }
        cout << read(1,n,root[l],1,x).val << '\n';
    }
}
