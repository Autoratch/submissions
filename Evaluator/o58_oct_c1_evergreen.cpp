#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n;
long long k,l,r,a[N];

bool solve(long long x)
{
    long long res = 0;
    for(int i = 0;i < n;i++)
    {
        res+=x*x;
        if(i and a[i-1]+x-1LL>=a[i]-x+1LL) 
        {
            long long tm = a[i-1]-a[i]+x*2LL-1LL,tmp;
            if(tm%2LL==1LL) tmp = ((tm+1LL)/2LL)*((tm+1LL)/2LL);
            else{ tm/=2LL; tmp = tm*(tm+1LL); }
            res-=tmp;
        }
    };
    if(res>=k) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    
    r = sqrt(k)+1LL;

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);

    while(l<r)
    {
        long long m = (l+r)/2LL;
        bool ok = solve(m);
        if(ok) r = m;
        else l = m+1LL;
    }

    cout << l-1;
}
