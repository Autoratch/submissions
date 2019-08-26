#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s;
vector<pair<int,int> > a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true)
    {
        cin >> n;
        if(!n) return 0;
        a.resize(n);
        for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
        sort(a.begin(),a.end());
        s.resize(0);
        for(int i = 0;i < n;i++)
        {
            int x = a[i].second;
            auto it = upper_bound(s.begin(),s.end(),x);
            if(it==s.end()) s.push_back(x);
            else *it = x;
        }
        cout << s.size() << '\n';
    }
}
