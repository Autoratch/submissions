#include <bits/stdc++.h>
using namespace std;

long long n,k,q,mxlv,lv[51];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> q;

    lv[0] = 1;
    for(long long i = 1;i <= 50;i++){ lv[i] = lv[i-1]*k; if(lv[i]>n){ mxlv = i; break; } }
    for(long long i = 1;i <= mxlv;i++) lv[i]+=lv[i-1];

    while(q--)
    {
        long long a,b,ans = 0;
        cin >> a >> b;
        if(k==1){ cout << abs(a-b) << '\n'; continue; }
        if(a>b) swap(a,b);
        long long lva = lower_bound(lv,lv+mxlv+1,a)-lv;
        long long lvb = lower_bound(lv,lv+mxlv+1,b)-lv;
        while(lvb!=lva) ans++,b = ceil((double)(b-1)/k),lvb--;
        while(a!=b) ans+=2,a = ceil((double)(a-1)/k),b = ceil((double)(b-1)/k);
        cout << ans << '\n';
    }
}
