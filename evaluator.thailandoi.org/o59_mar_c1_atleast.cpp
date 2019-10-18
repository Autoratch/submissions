#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long n,m;
double va[N];
long long a[N],s[N],am[N],st[N],en[N],mid[N],l[N],r[N],qs[N],ans[N];
pair<long long,long long> res[N];
vector<long long> idx[N];

void update(long long idx,long long val,long long *a){ while(idx<=n) a[idx]+=val,idx+=(idx & -idx); }

long long read(long long idx,long long *a){ if(idx==0) return 0; long long val = 0; while(idx>0) val+=a[idx],idx-=(idx & -idx); return val; }

int main()
{
 //   ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(long long i = 1;i <= n;i++) cin >> a[i],res[i] = {a[i],i},qs[i] = qs[i-1]+a[i];

    for(long long i = 0;i < m;i++) cin >> st[i] >> en[i] >> va[i];

    for(long long i = 0;i < m;i++) l[i] = 0,r[i] = n;

    sort(res+1,res+n+1);

    bool state = true;
    while(true)
    {
        state = false;
        for(long long i = 0;i <= n;i++) idx[i].clear();
        for(long long i = 0;i < m;i++) if(l[i]<r[i])
        {
            state = true;
            mid[i] = (l[i]+r[i])/2;
            idx[mid[i]].push_back(i);
        }
        for(long long i = 1;i <= n;i++) s[i] = am[i] = 0;
        if(!state)
        {
            for(long long i = 0;i < m;i++) idx[l[i]].push_back(i);
            for(long long i = 1;i <= n;i++)
            {
                if(i)
                {
                    update(res[i].second,res[i].first,s);
                    update(res[i].second,1,am);
                    for(long long x : idx[i]) 
                    {
                        ans[x] = read(en[x],am)-read(st[x]-1,am);
                    }
                }
            }
            for(long long i = 0;i < m;i++) if(ans[i]==en[i]-st[i]+1) ans[i] = -1;
            for(long long i = 0;i < m;i++) cout << ans[i] << '\n';
            return 0;
        }
        else
        {
            for(long long i = 0;i <= n;i++)
            {
                if(i)
                {
                    update(res[i].second,res[i].first,s);
                    update(res[i].second,1,am);
                }
                for(long long x : idx[i])
                {
                    long long tmp = read(en[x],s)-read(st[x]-1,s);
                    long long amt = read(en[x],am)-read(st[x]-1,am);
                    if((double)((double)(qs[en[x]]-qs[st[x]-1]-tmp)/(double)(en[x]-st[x]+1-amt))>=(double)va[x]) r[x] = mid[x];
                    else l[x] = mid[x]+1;
                }
            }
        }
    }
}
