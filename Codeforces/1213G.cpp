#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 1;

long long n,m;
vector<pair<long long,pair<long long,long long> > > adj;
long long pa[N],sz[N];
long long ans;
vector<pair<long long,long long> > res;

long long root(long long x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(long long i = 1;i <= n;i++) pa[i] = i,sz[i] = 1;

    for(long long i = 0;i < n-1;i++)
    {
        long long a,b,d;
        cin >> a >> b >> d;
        adj.push_back({d,{a,b}});
    }

    sort(adj.begin(),adj.end());

    for(long long i = 0;i < n-1;i++)
    {
        long long a = adj[i].second.first,b = adj[i].second.second;
        long long d = adj[i].first;
        if(root(a)==root(b)) continue;
        long long x = sz[root(a)],y = sz[root(b)];
        ans-=(x*(x-1))/2;
        ans-=(y*(y-1))/2;
        long long ra = root(a);
        pa[ra] = root(b);
        sz[root(b)]+=sz[ra];
        x = sz[root(b)];
        ans+=(x*(x-1))/2;
        res.push_back({d,ans});
    }

    for(long long i = 0;i < m;i++)
    {
        long long x;
        cin >> x;
        auto it = upper_bound(res.begin(),res.end(),make_pair(x,LLONG_MAX));
        if(it==res.begin()) cout << "0 ";
        else
        {
            it--;
            cout << it->second << ' ';
        }
    }
}