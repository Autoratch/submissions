#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n,a[N];
int ans[N],need[N];
pair<int,int> so[N];

struct node
{
    int mn,mx;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.mn = min(a.mn,b.mn);
        ret.mx = max(a.mx,b.mx);
        return ret;
    }
}tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].mn = tree[idx].mx = a[l]; return; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret = {INT_MAX}; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i],a[i+n] = a[i],so[i] = {-a[i],i};

    build(0,n*2-1,1);

    for(int i = 0;i < n;i++)
    {
        int l = i+1,r = n*2-1;
        while(l<r)
        {
            int m = (l+r)/2;
            if(read(0,n*2-1,1,l,m).mx>a[i]) r = m;
            else l = m+1;
        }
        int ed = l;
        r = l,l = i+1;
        while(l<r)
        {
            int m = (l+r)/2;
            if(read(0,n*2-1,1,l,m).mn*2<a[i]) r = m;
            else l = m+1;
        }
        int ki = l;
//        cout << i << ' ' << ed << ' ' << ki << endl;
        if(ed==n*2-1 and ki==n*2-1) ans[i] = -1;
        else if(ed==n*2-1) ans[i] = ki-i;
        else if(ki<ed) ans[i] = ki-i;
        else need[i] = ed;
    }

    sort(so,so+n);

    for(int i = 0;i < n;i++)
    {
        int x = so[i].second;
        if(!need[x]) continue;
        if(need[x]>=n) need[x]-=n;
        if(ans[need[x]]==-1) ans[x] = -1;
        else ans[x] = ans[need[x]]+(need[x]-x+n)%n;
    }

    for(int i = 0;i < n;i++) cout << ans[i] << ' ';
}
