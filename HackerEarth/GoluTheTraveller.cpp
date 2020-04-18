#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

int t,n;
map<string,pair<string,int> > ma;
set<string> f;
vector<string> v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        ma.clear();
        f.clear();
        v.clear();
        for(int i = 0;i < n-1;i++)
        {
            string a,b;
            int d;
            cin >> a >> b >> d;
            ma[a] = {b,d};
            f.insert(a);
            v.push_back(b);
        }
        for(string x : v) if(f.find(x)!=f.end()) f.erase(f.find(x));
        string x = *(f.begin());
        int ans = 0;
        for(int i = 0;i < n-1;i++)
        {
            cout << x << ' ' << ma[x].first << ' ' << ma[x].second << '\n';
            ans+=ma[x].second;
            x = ma[x].first;
        }
        cout << ans << '\n';
    }
}
