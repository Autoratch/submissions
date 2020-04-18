#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;

int n;
long long ans,b[N];
pair<long long,long long> a[N];
struct node{ long long val; friend node operator+(const node &a,const node &b){ if(a.val>b.val) return a; else return b; } };
node tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r) return void(tree[idx].val = a[l].second);
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {LLONG_MIN};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].first >> a[i].second;
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) b[i] = a[i].second;
    for(int i = 2;i <= n;i++) a[i].second-=a[i].first-a[i-1].first;
    for(int i = 2;i <= n;i++) a[i].second+=a[i-1].second;
    build(1,n,1);
    for(int i = 1;i < n;i++)
    {
        long long each = read(1,n,1,i+1,n).val;
        if(each==LLONG_MIN) each = -1;
        each-=a[i].second;
        ans = max(ans,b[i]+max(each,0LL));
    }
    ans = max(ans,b[n]);
    cout << ans;
}
