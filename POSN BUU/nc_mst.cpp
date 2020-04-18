#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 1;
const int MOD = 1e9 + 7;

int n,m;
vector<pair<int,int> > adj[N];
map<int,vector<pair<int,int> > > wei;
long long ms,ans = 1;
int pa[N];

int root(int x){ if(pa[x]==x) return x; return pa[x] = root(pa[x]); }

void cal()
{
    for(int i = 1;i <= n;i++) pa[i] = i;
    for(auto it : wei)
    {
        for(auto itt = it.second.begin();itt != it.second.end();) 
        {
            int a = (*itt).first,b = (*itt).second;
            if(root(a)==root(b)) itt = it.second.erase(itt);
            else itt++;
        }
        if(it.second.size()==2)
        {
            int a = it.second[0].first,b = it.second[0].second;
            int c = it.second[1].first,d = it.second[1].second;
            a = root(a),b = root(b),c = root(c),d = root(d);
            set<int> s;
            s.insert(a),s.insert(b),s.insert(c),s.insert(d);
            if(s.size()==2) ans = (ans*2LL)%MOD;
        }
        else if(it.second.size()==3)
        {
            int a = it.second[0].first,b = it.second[0].second;
            int c = it.second[1].first,d = it.second[1].second;
            int e = it.second[2].first,f = it.second[2].second;
            a = root(a),b = root(b),c = root(c),d = root(d),e = root(e),f = root(f);
            if(a>b) swap(a,b);
            if(c>d) swap(c,d);
            if(e>f) swap(e,f);
            set<int> s;
            s.insert(a),s.insert(b),s.insert(c),s.insert(d),s.insert(e),s.insert(f);
            if(s.size()==2) ans = (ans*3LL)%MOD; 
            else if(s.size()>=3) 
            {
                if(a==c and b==d) ans = (ans*2LL)%MOD;
                else if(a==e and b==f) ans = (ans*2LL)%MOD;
                else if(c==e and d==f) ans = (ans*2LL)%MOD;
                else if(s.size()==3) ans = (ans*3LL)%MOD;
            }
        }
        for(auto itt : it.second)
        {
            int d = it.first,a = itt.first,b = itt.second;
            if(root(a)==root(b)) continue;
            pa[root(a)] = root(b);
            ms = (ms+(long long)d)%MOD;
        }
   }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        if(a==b) continue;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
        if(a>b) swap(a,b);
        wei[d].push_back(make_pair(a,b));
    }
    cal();
    cout << ms%MOD << ' ' << ans%MOD;
}
