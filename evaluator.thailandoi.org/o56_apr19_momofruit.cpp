#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a,s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) a[i]+=a[i-1];
    for(int i = 0;i < n;i++)
    {
        if(a[i]<=0) continue;
        auto it = lower_bound(s.begin(),s.end(),a[i]);
        if(i==n-1) cout << (int)(it-s.begin())+1;
        if(it==s.end()) s.push_back(a[i]);
        else *it = a[i];
    }
}
