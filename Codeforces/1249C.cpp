#include <bits/stdc++.h>
using namespace std;

int t;
long long n,ans,mul;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        a.clear();
        int nn = n;
        while(n)
        {
            a.push_back(n%3LL);
            n/=3LL;
        }
        a.push_back(0);
        ans = 0LL;
        mul = 1;
        for(int i = 0;i < a.size();i++) 
        {
            if(i) mul*=3LL;
            if(a[i]<2){ ans = ans+mul*(long long)a[i]; continue; }
            a[i] = 0;
            a[i+1]++;
            for(int j = i;j >= 0;j--) a[j] = 0;
        }
        mul = 1;
        ans = 0;
        for(int i = 0;i < a.size();i++) ans+=mul*(long long)a[i],mul*=3LL;
        cout << ans << '\n';
    }
}
