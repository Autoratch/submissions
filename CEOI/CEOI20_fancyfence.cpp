#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<long long,long long>,long long> 

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

int n;
long long h[N],w[N],lst;
pii a[N];
set<pii> s;
priority_queue<pair<long long,long long> > q;
long long ans;
bool done;

void add(pii x)
{
    s.insert(x);
    auto it = s.lower_bound(x);
    if(it!=s.begin())
    {
        auto il = it; il--;
        if(il->second==it->second) 
        {
            pii tmp = {{il->first.first,it->first.second},il->second};
            it = s.erase(il);
            s.erase(it);
            s.insert(tmp);
        }
    }
}

void query(long long l,long long h)
{
    auto it = s.upper_bound({{l,LLONG_MAX},LLONG_MAX});
    it--;
    if(it->second!=h) return;
    long long ah = h,al = 0;
    auto ix = it;
    bool le = false,re = false;
    if(it!=s.begin())
    {
        ix--;
        le = true;
        al = max(al,ix->second);
    }
    ix = it,ix++;
    if(ix!=s.end())
    {
        al = max(al,ix->second);
        re = true;
    }
    al++;
    long long ve = it->first.second-it->first.first+1LL;
    ve%=MOD;
    ve = ((ve*(ve-1LL))/2LL)%MOD;
    long long ho = ((al+ah)*(ah-al+1LL)/2LL)%MOD;
    ans = ((ho*ve)%MOD+ans)%MOD;
    if(al==1) return void(done = true);
    if(le)
    {
        ix = it;
        ix--;
        if(ix->second==al-1) 
        {
            pii tmp = {{ix->first.first,it->first.second},ix->second};
            it = s.erase(ix);
            s.erase(it);
            s.insert(tmp);
            it = s.lower_bound(tmp);
        }
    }
    if(re)
    {
        ix = it;
        ix++;
        if(ix->second==al-1)
        {
            pii tmp = {{it->first.first,ix->first.second},ix->second};
            it = s.erase(it);
            s.erase(it);
            s.insert(tmp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        a[i] = {{lst,lst+w[i]},h[i]};
        lst+=w[i];
    }
    for(int i = 1;i <= n;i++) add(a[i]);
    for(pii x : s) q.push({x.second,x.first.first});
    while(!q.empty())
    {
        long long h = q.top().first,l = q.top().second;
        q.pop();
        query(l,h);
        if(done) break;
    }
    cout << ans;
}
