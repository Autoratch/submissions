#include <bits/stdc++.h>
using namespace std;

const int N = 5e3;
const int M = 1e5 + 1;

int n,m,t,mx;
int pa[N];
vector<pair<int,pair<int,int> > > ed(M);
vector<int> cmp(M);

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> t;

    for(int i = 0;i < n;i++) pa[i] = i;

    for(int i = 1;i <= m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        ed[i] = {d,{a,b}};
    }

    sort(ed.begin()+1,ed.begin()+m+1);
    cmp[0] = -n;

    for(int i = 1;i <= m;i++)
    {
        int a = ed[i].second.first,b = ed[i].second.second;
        cmp[i] = cmp[i-1];
        if(root(a)==root(b)) continue;
        pa[root(a)] = root(b);
        cmp[i]++;
    }

    while(t--)
    {
        int x;
        cin >> x;
        auto it = lower_bound(cmp.begin(),cmp.end(),-x);
        cout << ed[(int)(it-cmp.begin())].first << '\n';
    }
}

