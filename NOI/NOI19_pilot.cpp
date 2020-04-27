#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,m;
pair<int,int> a[N],q[N];
int lr[N];
bool s[N];
long long ans[N],now;

void add(int x)
{
    int ll = x,rr = x;
    long long l = 0,r = 0;
    if(ll>1 and s[ll-1]) l = ll-1-lr[ll-1]+1,ll = lr[ll-1];
    if(rr<n and s[rr+1]) r = lr[rr+1]-(rr+1)+1,rr = lr[rr+1];
    now+=(l+1LL)*(r+1LL);
    lr[ll] = rr,lr[rr] = ll;
    s[x] = true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].first,a[i].second = i;
    for(int i = 1;i <= m;i++) cin >> q[i].first,q[i].second = i;
    sort(q+1,q+m+1),sort(a+1,a+n+1);
    int x = 1,y = 1;
    while(y<=m)
    {
        while(x<=n and a[x].first<=q[y].first) add(a[x].second),x++;
        ans[q[y].second] = now,y++;
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';
}
