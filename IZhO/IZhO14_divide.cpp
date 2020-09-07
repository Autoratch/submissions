#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
long long x[N],g[N],e[N];
set<pair<long long,long long> > s;
long long ans;
    
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> x[i] >> g[i] >> e[i],e[i]+=e[i-1],g[i]+=g[i-1];
    for(int i = 1;i <= n;i++)
    {
        auto it = s.upper_bound({e[i]-x[i],INT_MAX});
        if(it!=s.begin())
        {
            it--;
            ans = max(ans,g[i]-it->second);
        }
        else ans = max(ans,g[i]-g[i-1]);
        it = s.upper_bound({e[i-1]-x[i],INT_MAX});
        bool out = false;
        if(it!=s.begin())
        {
            it--;
            if(it->second<g[i-1]) out = true;
        }
        if(out) continue;
        it = s.lower_bound({e[i-1]-x[i],INT_MAX});
        while(it!=s.end() and it->second>=g[i-1]) it = s.erase(it);
        s.insert({e[i-1]-x[i],g[i-1]});
    }
    cout << ans;
}
