#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 2LL;

long long n;
long long a[N],s[N],dl[N],dr[N],t[N];
long long ans = LLONG_MAX;
set<long long> res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 1;i <= n;i++) cin >> a[i],s[i] = s[i-1]+a[i];
    for(long long i = n;i >= 1;i--) t[i] = t[i+1]+a[i];

    res.insert(a[1]);
    for(long long i = 2LL;i <= n;i++)
    {
        auto itr = res.upper_bound(s[i]/2LL);
        auto itl = itr; itl--;
        dl[i] = LLONG_MAX;
        if(itr!=res.end()) dl[i] = min(dl[i],abs(*itr-(s[i]-*itr)));
        if(itr!=res.begin()) dl[i] = min(dl[i],abs(*itl-(s[i]-*itl)));

//        cout << *itl << ' ' << *itr << ' ' << dl[i] << endl;

        res.insert(s[i]);
    }

    res.clear();
    res.insert(a[n]);
    for(long long i = n-1;i >= 1;i--)
    {
        auto itr = res.upper_bound(t[i]/2LL);
        auto itl = itr; itl--;
        dr[i] = LLONG_MAX;
        if(itr!=res.end()) dr[i] = min(dr[i],abs(*itr-(t[i]-*itr)));
        if(itr!=res.begin()) dr[i] = min(dr[i],abs(*itl-(t[i]-*itl)));
        res.insert(t[i]);
    }

    for(long long i = 2LL;i < n-1;i++)
    {
        long long el = i,sr = i+1;
        long long a = (s[el]+dl[el])/2LL,b = (s[el]-dl[el])/2LL;
        long long c = (t[sr]+dr[sr])/2LL,d = (t[sr]-dr[sr])/2LL;
        if(a<b) swap(a,b);
        if(c<d) swap(c,d);
        ans = min(ans,max(max(c-b,a-d),max(dl[el],dr[sr])));
    }

    cout << ans;
}
