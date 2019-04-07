#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
pair<string,int> p[N];
vector<string> s;
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    s.resize(n);

    for(int i = 0;i < n;i++){ cin >> s[i]; s[i][s[i].length()-1] = 'M'; p[i] = {s[i],i}; }
   
    sort(s.begin(),s.end());
    auto it = unique(s.begin(),s.end());
    s.resize(distance(s.begin(),it));
    sort(p,p+n);

    for(int i = 0;i < s.end()-s.begin();i++)
    {
        auto lo = lower_bound(p,p+n,make_pair(s[i],INT_MIN));
        auto up = lower_bound(p,p+n,make_pair(s[i],INT_MAX));
        for(auto it = lo;it != up;it++) ans[it->second] = i+1;
    }

    for(int i = 0;i < n;i++) cout << ans[i] << '\n';
}
