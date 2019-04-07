#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a,s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    a.resize(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        auto it = lower_bound(s.begin(),s.end(),a[i]);
        if(it==s.end()) s.push_back(a[i]);
        else *it = a[i];
    }

    cout << s.size();
}
