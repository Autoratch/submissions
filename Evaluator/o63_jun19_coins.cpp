#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 2;

long long n,cir;
long long a[N],s[N],qs[N];
vector<long long> loc[N];
set<pair<long long,long long> > fin[N];

long long dist(long long x,long long y)
{
    if(y>=x) return qs[y-1]-qs[x-1];
    else return cir-(qs[x-1]-qs[y-1]);
}

void add(set<pair<long long,long long> > &s,long long idx,long long val)
{
    if(s.empty()) return void(s.insert({idx,val}));
    auto it = s.lower_bound(make_pair(idx,val));
    auto itl = it;
    if(it==s.begin()) itl = s.end(),itl--;
    else itl--;
    if(min(dist(idx,itl->first),dist(itl->first,idx))+itl->second<=val) return;
    auto itr = it;
    if(itr==s.end()) itr = s.begin();
    if(min(dist(idx,itr->first),dist(itr->first,idx))+itr->second<=val) return;
    s.insert({idx,val});
    it = s.lower_bound(make_pair(idx,val));
    auto idl = it;
    if(idl==s.begin()) idl = s.end();
    idl--;
    while(true)
    {
        if(idl==it) break;
        if(min(dist(idx,idl->first),dist(idl->first,idx))+val<=idl->second){ idl = s.erase(idl); if(idl==s.begin()) idl = s.end(); idl--; }
        else break;
    }
    auto idr = it;
    idr++;
    if(idr==s.end()) idr = s.begin();
    while(true)
    {
        if(idr==it) break;
        if(min(dist(idx,idr->first),dist(idr->first,idx))+val<=idr->second){ idr = s.erase(idr); if(idr==s.end()) idr = s.begin(); }
        else break;
    }
}

long long find(set<pair<long long,long long> > &s,long long idx)
{
    auto itr = s.lower_bound(make_pair(idx,INT_MAX));
    auto itl = itr; 
    if(itr==s.begin()) itl = s.end(),itl--;
    else itl--;
    if(itr==s.end()) itr = s.begin();
    long long x = min(dist(itl->first,idx),dist(idx,itl->first))+itl->second;
    long long y = min(dist(itr->first,idx),dist(idx,itr->first))+itr->second;
    return min(x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(long long i = 1;i <= n;i++) cin >> a[i];
    for(long long i = 1;i <= n;i++) cin >> s[i],cir+=s[i],qs[i] = s[i]+qs[i-1];
    for(long long i = 1;i <= n;i++) loc[a[i]].push_back(i);
    for(long long i = 1;i <= n+1;i++)
    {
        if(!loc[i].size())
        {
            long long ans = LLONG_MAX;
            for(auto [x,y] : fin[i-1]) ans = min(ans,y);
            cout << ans;
            break;
        }
        if(i==1) 
        {
            for(long long j = 0;j < loc[i].size();j++)
            {
                long long r = j+1,l = j-1;
                if(r==loc[i].size()) r = 0;
                if(l<0) l = loc[i].size()-1;
                add(fin[i],loc[i][j],min(dist(loc[i][r],loc[i][j]),dist(loc[i][j],loc[i][l])));
            }
        }
        else
        {
            for(long long j = 0;j < loc[i].size();j++) 
            {
                long long old = find(fin[i-1],loc[i][j]);
                long long r = j+1,l = j-1;
                if(r==loc[i].size()) r = 0;
                if(l<0) l = loc[i].size()-1;
                add(fin[i],loc[i][l],dist(loc[i][j],loc[i][l])+old);
                add(fin[i],loc[i][r],dist(loc[i][r],loc[i][j])+old);
            }
        }
    }
}
