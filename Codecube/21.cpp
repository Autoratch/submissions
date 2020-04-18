#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 15;

int n,q;
int a[N];
vector<int> res[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ res[idx].push_back(a[l]); return; }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    for(int i = l;i <= r;i++) res[idx].push_back(a[i]);
    sort(res[idx].begin(),res[idx].end());
}

int read(int l,int r,int idx,int x,int y,int s,int e)
{
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) return upper_bound(res[idx].begin(),res[idx].end(),e)-lower_bound(res[idx].begin(),res[idx].end(),s);
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y,s,e)+read(m+1,r,idx*2+1,x,y,s,e);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,n,1);

    while(q--)
    {
        int a,b,s,e;
        cin >> a >> b >> s >> e;
        cout << read(1,n,1,a,b,s,e) << ' ';
    }
}
