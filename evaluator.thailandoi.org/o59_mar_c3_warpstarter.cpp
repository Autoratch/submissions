#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long n,k;
pair<long long,long long> a[N];
set<long long> s;
unordered_map<long long,long long> hsh,hss;
long long val[N],now,ans;
long long fw[N];

bool compare(const pair<long long,long long> &a,const pair<long long,long long> &b){ return a.second<b.second; }

void update(long long idx,long long val){ while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

long long read(long long idx){ long long val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

long long where(long long x)
{
    long long l = 1,r = n;
    while(l<r)
    {
        long long m = (l+r)/2;
        if(read(m)<x) l = m+1;
        else if(read(m)>x) r = m-1;
        else if(read(m)==x) r = m;
    }
    return hss[val[l]];
}

long long dist(long long x,long long y){ return abs(a[x].first-a[y].first)+abs(a[x].second-a[y].second);}

void add(long long x)
{
    long long id = x;
    x = hsh[a[x].first];
    long long bf = read(x);
    if(bf==0){ if(read(n)) now+=dist(where(1),id); }
    else
    {
        if(bf==read(n)) now+=dist(where(read(n)),id);
        else now+=dist(where(bf),id)+dist(where(bf+1),id)-dist(where(bf),where(bf+1));
    }
    update(x,1);
}

void del(long long x)
{
    long long id = x;
    x = hsh[a[x].first];
    if(read(n)>1)
    {
        if(read(x)==1) now-=dist(where(2),id);
        else if(read(x)==read(n)) now-=dist(where(read(n)-1),id);
        else now-=dist(where(read(x)+1),id)+dist(where(read(x)-1),id)-dist(where(read(x)+1),where(read(x)-1));
    }
    update(x,-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(long long i = 0;i < n;i++) cin >> a[i].first >> a[i].second,s.insert(a[i].first);
    sort(a,a+n,compare);
    for(long long i = 0;i < n;i++) hss[a[i].first] = i;
    long long idx = 0;
    for(long long x : s) hsh[x] = ++idx,val[idx] = x;
    for(long long i = 0;i < k;i++)
    {
        add(i);
    }
    ans = now;
    for(long long i = k;i < n;i++)
    {
        del(i-k);
        add(i);
        ans = min(ans,now);
    }
    cout << ans;
}
