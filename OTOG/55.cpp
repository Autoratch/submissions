#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
int a[N],s[N],d[N],st[N],en[N],t[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 2;i < n;i++) if(a[i-1]>a[i] and a[i+1]>a[i]) s[i] = s[i-1]+1; else s[i] = s[i-1];

    int cur = 0;
    for(int i = 1;i <= n;i++)
    {
        if(i==1) d[i] = cur,st[cur] = en[cur] = i;
        else if(a[i]==a[i-1]) d[i] = cur,en[cur] = i;
        else cur++,d[i] = cur,st[cur] = i,en[cur] = i;
    }

    for(int i = 0;i <= n;i++)
    {
        if(st[i]==0) break;
        t[i]+=t[i-1];
        int l = st[i],r = en[i];
        if(l==1 or r==n) continue;
        if(a[l-1]>a[l] and a[r+1]>a[r]) t[i]++;
    }

    while(m--)
    {
        int l,r;
        cin >> l >> r;
        if(r-l<=1){ cout << "Yes\n"; continue; }
        else if(s[r-1]-s[l]){ cout << "No\n"; continue; }
        int xl = d[l]+1,xr = d[r]-1;
        if(xl<=xr and t[xr]-t[xl-1]){ cout << "No\n"; continue; }
        cout << "Yes\n";
    }
}
