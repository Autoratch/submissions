#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int n;
long long k;
tuple<long long,int,int> s[N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1;i <= n;i++) 
    {
        int a,b,d;
        cin >> d >> a >> b;
        s[i] = {d,a,b};
    }
    sort(s+1,s+n+1);
    ans = get<0>(s[1]);
    while(true)
    {
        bool ok = true;
        long long now = ans,lst = 0,more = 0;
        for(int i = 1;i <= n;i++)
        {
            auto [d,a,b] = s[i];
            now-=d-lst;
            if(now<0) ok = false,more+=-now,now = 0;
            if(ans<=b) now+=a;
            lst = d;
        }
        now-=k-lst;
        if(now<0) ok = false,more+=-now,now = 0;
        if(ok){ cout << ans; return 0; }
        ans+=more;
    }
}
