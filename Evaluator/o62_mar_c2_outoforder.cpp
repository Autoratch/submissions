#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n;
long long ans;
int h[N],d[N];
vector<int> tree[N << 1];

void build(int l,int r,int idx)
{
    for(int i = l;i <= r;i++) tree[idx].push_back(h[i]);
    sort(tree[idx].begin(),tree[idx].end());
    if(l==r) return;
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
}

int read(int l,int r,int idx,int x,int y,int mn,int mx)
{
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) 
    {
        auto itl = lower_bound(tree[idx].begin(),tree[idx].end(),mn);
        auto itr = upper_bound(tree[idx].begin(),tree[idx].end(),mx);
        return itr-itl;
    }
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y,mn,mx)+read(m+1,r,idx*2+1,x,y,mn,mx);
}

int main()
{ 
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> h[i];

    for(int i = 1;i <= n;i++) cin >> d[i];

    build(1,n,1);

    for(int i = 1;i <= n;i++)
    {
        int l = i-d[i],r = i+d[i];
        l = max(l,1),r = min(r,n);
        ans+=(long long)read(1,n,1,l,i-1,h[i]+1,INT_MAX)+(long long)read(1,n,1,i+1,r,INT_MIN,h[i]-1);
    }

    cout << ans;
}
