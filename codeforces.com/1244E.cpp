#include <bits/stdc++.h>
using namespace std;

long long n;
long long k;
vector<long long> a;
long long s[(int)1e5];
long long ans = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a.begin(),a.end());
    for(int i = 0;i < n;i++){ s[i] = a[i]; if(i) s[i]+=s[i-1]; }

    long long l = 0,r = a[a.size()-1]-a[0];

    while(l<r)
    {
        long long m = (l+r)/2LL;
        bool f = false;
        for(long long i = 0;i < n;i++)    
        {
            auto it = upper_bound(a.begin(),a.end(),a[i]+m);
            int idx = it-a.begin();
            long long sum = s[n-1];
            if(idx) sum-=s[idx-1];
            long long tmp = sum-(a[i]+m)*(n-idx);
            if(i)
            {
                sum = s[i-1];
                sum = a[i]*i-sum;
                tmp+=sum;
            }
 //           cout << tmp << endl;
            if(tmp<=k) f = true;
        }
//        cout << l << ' ' << r << ' ' << m << ' ' << f << endl;
        if(f) r = m;
        else l = m+1LL;
    }
ans = min(ans,l);

    for(int i = 0;i < n;i++) a[i] = 1e9+1-a[i];

    sort(a.begin(),a.end());

     for(int i = 0;i < n;i++){ s[i] = a[i]; if(i) s[i]+=s[i-1]; }

 l = 0,r = a[a.size()-1]-a[0];

    while(l<r)
    {
        long long m = (l+r)/2LL;
        bool f = false;
        for(int i = 0;i < n;i++)    
        {
            auto it = upper_bound(a.begin(),a.end(),a[i]+m);
            int idx = it-a.begin();
            long long sum = s[n-1];
            if(idx) sum-=s[idx-1];
            long long tmp = sum-(a[i]+m)*(n-idx);
            if(i)
            {
                sum = s[i-1];
                sum = a[i]*i-sum;
                tmp+=sum;
            }
 //           cout << tmp << endl;
            if(tmp<=k) f = true;
        }
//        cout << l << ' ' << r << ' ' << m << ' ' << f << endl;
        if(f) r = m;
        else l = m+1LL;
    }

   ans = min(ans,l);

    cout << ans;
}
