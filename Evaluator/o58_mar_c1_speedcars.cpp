#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,t,ans;
map<int,vector<pair<int,int> > > m;
bool out[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        cin >> x >> y;
        m[x+y*t].push_back({x,i});
    }
    auto it2 = m.end(); it2--;
    int mn = INT_MAX;
    for(auto it = it2;;it--)
    {
        vector<pair<int,int> > &a = it->second;
        int each = INT_MAX;
        for(auto [x,y] : a){ if(mn<=x) out[y] = true; each = min(each,x); }
        for(auto [x,y] : a){ if(each<x) out[y] = true; }
        mn = min(mn,each);
        if(it==m.begin()) break;
    }
    for(int i = 1;i <= n;i++) if(!out[i]) ans++;
    cout << ans;
}
