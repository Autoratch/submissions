#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
pair<string,int> p[N];
string s[N];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++){ cin >> s[i]; s[i][s[i].length()-1] = 'M'; p[i] = {s[i],i}; }
    
    sort(s,s+n);
    sort(p,p+n);

    for(int i = 0;i < n;i++)
    {
        auto it = lower_bound(p,p+n,make_pair(s[i],INT_MIN));
        ans[it->second] = i+1;
    }

    for(int i = 0;i < n;i++) cout << ans[i] << '\n';
}
