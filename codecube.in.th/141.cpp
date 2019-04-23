#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,w,k;
int a[N],b[N];

int solve(int x)
{
    int ans = 0;
    memset(b,0,sizeof b);
    for(int i = 0;i < n;i++)
    {
        if(i) b[i]+=b[i-1];
        int now = a[i]-x;
        if(now<=b[i]) continue;
        int l = now-b[i];
        ans+=l;
        b[i]+=l;
        b[i+w]-=l;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> w >> k;
    for(int i = 0;i < n;i++) cin >> a[i];

    int l = 0,r = 1e9;
    while(l<r)
    {
        int m = (l+r)/2;
        if(solve(m)<=k) r = m;
        else l = m+1;
    }

    cout << l;
}
