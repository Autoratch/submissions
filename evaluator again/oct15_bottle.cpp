#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,q;
int a[N];
set<pair<int,int> > s;
set<int> tmp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        s.insert({x,i});
        a[i] = x;
    }

    while(q--)
    {
        int x;
        cin >> x;
        auto it = s.upper_bound(make_pair(x,INT_MAX));
        tmp.clear();   
        int ans = 0;
        for(;it != s.end();)
        {
            if(it->second>0) tmp.insert(it->second-1);
            if(it->second<n-1) tmp.insert(it->second+1);
            it = s.erase(it);
            ans++;
        }
        for(int i : tmp)
        {
            auto t = s.find(make_pair(a[i],i));
            if(t!=s.end()){ s.erase(t); ans++; }
        }
        cout << ans << '\n';
    }
}
