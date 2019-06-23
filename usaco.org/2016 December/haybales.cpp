#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<int> a;

int main()
{
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);

    cin >> n >> q;
    
    a.resize(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a.begin(),a.end());

    while(q--)
    {
        int x,y;
        cin >> x >> y;
        auto r = upper_bound(a.begin(),a.end(),y);
        auto l = lower_bound(a.begin(),a.end(),x);
        cout << r-l << '\n';
    }
}
