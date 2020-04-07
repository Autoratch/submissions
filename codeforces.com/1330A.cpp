#include <bits/stdc++.h>
using namespace std;

int t,n,x;
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        s.clear();
        for(int i = 0;i < n;i++){ int a; cin >> a; s.insert(a); }
        for(int i = 201;i >= 1;i--) 
        {
            auto it = s.upper_bound(i);
            int cnt = 0;
            for(auto it2 = s.begin();it2 != it;it2++,cnt++);
            if(cnt+x>=i){ cout << i << '\n'; break; }
        }
    }
}
