#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int t,n;
vector<pair<int,int> > ans;
int a[N],f[N],b[N];
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        int mx = 0;
        s.clear();
        for(int i = 1;i <= n;i++) s.insert(a[i]),mx = max(mx,a[i]),f[i] = (mx==i and s.size()==i);
        mx = 0; s.clear();
        for(int i = n;i >= 1;i--) s.insert(a[i]),mx = max(mx,a[i]),b[i] = (mx==n-i+1 and s.size()==n-i+1);
        ans.clear();
        for(int i = 1;i < n;i++) if(f[i] and b[i+1]) ans.push_back({i,n-i});
        cout << ans.size() << '\n';
        for(auto x : ans) cout << x.first << ' ' << x.second << '\n';
    }
}
