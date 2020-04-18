#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n,m;
pair<int,int> a[N];
struct node{ long long val,am; int left,right; }tree[N*100];
int root[N],cnt,cur;

int clone(int idx){ tree[++cnt] = tree[idx]; return cnt; }

void build(int l,int r,int idx)
{
    cnt = max(cnt,idx);
    if(l==r) return;
    int m = (l+r)/2;
    tree[idx].left = idx*2,tree[idx].right = idx*2+1;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
}

int update(int l,int r,int idx,int x,int y)
{
    int now = clone(idx);
    tree[now].val+=y,tree[now].am++;
    if(l==r) return now;
    int m = (l+r)/2;
    if(x<=m) tree[now].left = update(l,m,tree[idx].left,x,y);
    else tree[now].right = update(m+1,r,tree[idx].right,x,y);
    return now;
}

pair<long long,int> read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {0,0};
    if(x<=l and y>=r) return {tree[idx].val,tree[idx].am};
    int m = (l+r)/2;
    pair<long long,int> xx = read(l,m,tree[idx].left,x,y),yy = read(m+1,r,tree[idx].right,x,y);
    return {xx.first+yy.first,xx.second+yy.second};
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].first,a[i].second = i;
    sort(a+1,a+n+1);
    build(1,n,1);
    root[0] = 1;
    for(int i = n;i >= 1;i--) root[cur+1] = update(1,n,root[cur],a[i].second,a[i].first),cur++;
    while(m--)
    {
        int x,y;
        double k;
        cin >> x >> y >> k;
        int l = 1,r = n;
        while(l<r)
        {
            int m = (l+r+1)/2;
            pair<long long,int> p = read(1,n,root[m],x,y);
            double val = p.first,am = p.second;
            if(am==0) l = m+1;
            else if(val>=am*k) l = m;
            else r = m-1;
        }
        pair<long long,int> p = read(1,n,root[l],x,y);
        double val = p.first,am = p.second;
        if(am==0 or (val<am*k)) cout << "-1\n";
        else cout << y-x+1-am << '\n';
    }

}
