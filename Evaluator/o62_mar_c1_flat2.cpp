#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1; 

int n,w;
int a[N],res[N];
vector<pair<int,int> > b[N];
int ans[N];
set<pair<int,int> > s,now;

void add(int x,int y)
{
    int l = x,r = y;
    auto ups = s.upper_bound(make_pair(x,y)),los = ups; 
    auto upn = now.upper_bound(make_pair(x,y)),lon = upn;
    if(los!=s.begin())
    {
        los--;
        if((*los).second+1==x) l = (*los).first,s.erase(los);
    }
    if(lon!=now.begin())
    {
        lon--;
        if((*lon).second+1==x) l = (*lon).first,now.erase(lon);
    }
    if(ups!=s.end())
    {
        if((*ups).first==y+1) r = (*ups).second,s.erase(ups);
    }
    if(upn!=now.end())
    {
        if((*upn).first==y+1) r = (*upn).second,now.erase(upn);
    }
    now.insert({l,r});
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> w; ans[0] = -1;
    for(int i = 1;i <= n;i++) cin >> a[i],ans[i] = -1;
    for(int i = 1;i <= n;i++)
    {
        if(i>1 and a[i]==a[i-1]) res[i] = res[i-1];
        else res[i] = i;
        if(i==n or a[i+1]!=a[i]) b[a[i]].push_back({res[i],i});
    }
    for(int i = N-1;i >= 0;i--)
    {
        for(auto x : b[i]) add(x.first,x.second);
        for(auto x : now) if(ans[x.second-x.first]==-1) ans[x.second-x.first] = i;
        for(auto x : now) s.insert(x);
        now.clear();
    }
    if(w==-10) for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
    else cout << ans[w];
}
