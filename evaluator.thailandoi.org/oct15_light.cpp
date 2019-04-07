#include <bits/stdc++.h>
using namespace std;

const int MOD = 2007;

int n,m,ans;
vector<pair<int,int> > a,lr;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++)
    {
        int l,r;
        cin >> l >> r;
        a.push_back({l+1,0});
        a.push_back({r,0});
        lr.push_back({l+1,r});
    }

    a.push_back({0,0});
    a.push_back({5e8,0});
    sort(a.begin(),a.end());
    auto it = unique(a.begin(),a.end());
    a.resize(distance(a.begin(),it));

    for(int i = 0;i < lr.size();i++)
    {
        auto lo = lower_bound(a.begin(),a.end(),make_pair(lr[i].first,INT_MIN));
        auto up = upper_bound(a.begin(),a.end(),make_pair(lr[i].second,INT_MIN));
        lo->second = (lo->second+1)%MOD;
        up->second = ((up->second-1)%MOD+MOD)%MOD;
    }

    for(auto it = a.begin()+1;it != a.end();it++)
    {
        auto it2 = it; it2--;
        it->second = ((it->second+it2->second)%MOD+MOD)%MOD;
    }

    for(int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        auto it = lower_bound(a.begin(),a.end(),make_pair(x,INT_MAX));
        it--;
        ans = (ans+it->second)%MOD;
    }

    cout << ans;
}
