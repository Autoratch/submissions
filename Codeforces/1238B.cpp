#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        a.resize(n);
        for(int i = 0;i < n;i++) cin >> a[i],a[i] = -a[i];
        sort(a.begin(),a.end());
        auto it = unique(a.begin(),a.end());
        a.resize(distance(a.begin(),it));
        int ans = -1,eq = 0;
        for(int i = 0;i < a.size()-1;i++)
        {
            if(-a[i+1]-m*(i+1)<=0){ ans = i+1; break; }
        }
        if(ans==-1) ans = a.size();
        cout << ans-eq << '\n';
    }


}
