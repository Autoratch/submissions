#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;

int n,q;
long long s,t,a[N],ans,fw[N];

void update(int idx,long long val){ idx++; while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

long long read(int idx){ idx++; long long val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

long long cal(long long a,long long b)
{
    if(a<b) return (-s)*(b-a);
    else return t*(a-b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> s >> t;
    for(int i = 0;i <= n;i++) cin >> a[i],update(i,a[i]),update(i+1,-a[i]);
    for(int i = 0;i < n;i++) ans+=cal(a[i],a[i+1]);
    while(q--)
    {
        int l,r;
        long long x;
        cin >> l >> r >> x;
        ans-=cal(read(l-1),read(l));
        if(r<n) ans-=cal(read(r),read(r+1));
        update(l,x),update(r+1,-x);
        ans+=cal(read(l-1),read(l));
        if(r<n) ans+=cal(read(r),read(r+1));
        cout << ans << '\n';
    }
}
