#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
tuple<int,int,int> ed[N];
int add[N];
vector<pair<int,int> > adj[N];
int val[N],pa[N];
long long ans;
map<int,int> ma[N];
vector<long long> o;

int root(int x){ if(pa[x]==x) return x; return pa[x] = root(pa[x]); }

void dfs(int u,int p){ for(auto x : adj[u]) if(x.second!=p) val[x.second] = val[u]^x.first,dfs(x.second,u); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i < n;i++){ int a,b,d; cin >> a >> b >> d; adj[a].push_back({d,b}); adj[b].push_back({d,a}); ed[i] = tie(a,b,d); }
    for(int i = 0;i < n-1;i++) cin >> add[i];
    dfs(1,0);   
    for(int i = 1;i <= n;i++) pa[i] = i,ma[i][val[i]] = 1;
    for(int i = n-2;i >= 0;i--)
    {
        int a,b,d;
        tie(a,b,d) = ed[add[i]];
        int paa = root(a),pab = root(b);
        if(ma[paa].size()>ma[pab].size()) swap(paa,pab);
        for(auto it : ma[paa]) ans+=(long long)(ma[pab][it.first]*it.second);
        pa[paa] = pab;
        for(auto it : ma[paa]) ma[pab][it.first]+=it.second;
        o.push_back(ans);
    }
    for(int i = o.size()-1;i >= 0;i--) cout << o[i] << '\n';
    cout << "0\n";
}
