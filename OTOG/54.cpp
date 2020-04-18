#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;
        auto it = lower_bound(s.begin(),s.end(),x);
        if(it==s.end()) s.push_back(x);
        else *it = x;
    }

    cout << s.size();
}
