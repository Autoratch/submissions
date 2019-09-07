#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n,m;
int a[N],res[N],ans[N];
pair<int,int> b[N];
int tree[N << 1],lazy[N << 1];

void pushlz(int l,int r,int idx)
{
    if(!lazy[idx]) return;
    tree[idx] = lazy[idx];
    if(l!=r) lazy[idx*2] = lazy[idx*2+1] = lazy[idx];
    lazy[idx] = 0;
}

void update(int l,int r,int idx,int x,int y,int k)
{
    if(x>r or y<l) return;
    if(x<=l and y>=r)
    {
        lazy[idx] = k;
        pushlz(l,r,idx);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y,k),update(m+1,r,idx*2+1,x,y,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int read(int l,int r,int idx,int x)
{
    pushlz(l,r,idx);
    if(l==r) return tree[idx];
    int m = (l+r)/2;
    if(x<=m) return read(l,m,idx*2,x);
    else return read(m+1,r,idx*2+1,x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 0;i < m;i++) cin >> b[i].first,b[i].second = i;
    
    sort(b,b+m);

    update(0,m-1,1,0,m-1,a[1]);

    for(int i = 2;i <= n;i++)
    {
        int l = 0,r = m-1;
        while(l<r)
        {
            int mm = m;
            int m = (l+r)/2;
            if(read(0,mm-1,1,m)+b[m].first>=a[i]) r = m;
            else l = m+1;
        }
        res[0]++,res[l]--;  
        update(0,m-1,1,l,m-1,a[i]);
    }

    for(int i = 1;i < m;i++) res[i]+=res[i-1];
    for(int i = 0;i < m;i++) ans[b[i].second] = res[i];
    for(int i = 0;i < m;i++) cout << ans[i] << '\n';
}
