#include <bits/stdc++.h>
using namespace std;

const long long N = 2000;

long long n;
pair<long long,long long> a[N];
long long b[N],c[N];
pair<long long,long long> res[N];
vector<long long> used;
long long ans;
vector<long long> built;
vector<pair<long long,long long> > cnct;

long long dist(long long x,long long y){ return abs(a[x].first-a[y].first)+abs(a[x].second-a[y].second); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(long long i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
    for(long long i = 0;i < n;i++) cin >> b[i],res[i] = {b[i],i};
    for(long long i = 0;i < n;i++) cin >> c[i];
    sort(res,res+n);
    for(long long i = 0;i < n;i++)
    {
        long long x = res[i].second;
        long long old = LLONG_MAX;
        long long aa,bb;
        for(long long y : used) if(dist(x,y)*(c[x]+c[y])<old) old = dist(x,y)*(c[x]+c[y]),aa = x,bb = y;
        if(b[x]<old) built.push_back(x);
        else cnct.push_back({aa,bb});
        ans+=min(old,b[x]);
        used.push_back(x);
    }
    cout << ans << '\n';
    cout << built.size() << '\n';
    for(long long x : built) cout << x+1 << ' ';
    cout << '\n' << cnct.size() << '\n';
    for(auto x : cnct) cout << x.first+1 << ' ' << x.second+1 << '\n';
}