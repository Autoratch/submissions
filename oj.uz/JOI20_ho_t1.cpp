#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n;
int a[N],b[N],p[N];
struct node
{
    long long a,b;
    friend node operator+(const node &a,const node &b){ return {max(a.a,b.a),max(a.b,b.b)}; }
}tree[N << 1];
unordered_map<int,long long> ans;

void build(int l,int r,int idx)
{
    if(l==r) return void(tree[idx] = {a[l]-b[l],a[l+1]-b[l]});
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {0,0};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n+1;i++) cin >> a[i],p[i] = a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    sort(a+1,a+n+2),sort(b+1,b+n+1);
    build(1,n,1);
    for(int i = 1;i <= n+1;i++) 
    {
        long long l = 0,r = 0;
        if(i>1) l = read(1,n,1,1,i-1).a;
        if(i<=n) r = read(1,n,1,i,n).b;
        ans[a[i]] = max(l,r);
    }
    for(int i = 1;i <= n+1;i++) cout << ans[p[i]] << ' ';
}
