#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n,m;
int a[N];
set<pair<int,int> > s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++){ cin >> a[i]; s.insert({a[i],i}); }

    for(int i = 0;i < m;i++)
    {
        int x,ans = 0;
        vector<int> tmp;
        cin >> x;
        auto it = s.upper_bound(make_pair(x,INT_MAX));
        while(it!=s.end())
        {
            int res = it->second;
            tmp.push_back(res-1);
            tmp.push_back(res+1);
            it = s.erase(it);
            ans++;
        }
        for(int j : tmp)
        {
            auto t = s.find(make_pair(a[j],j));
            if(t!=s.end()){ s.erase(t); ans++; }
        }
        cout << ans << '\n';
    }
}
