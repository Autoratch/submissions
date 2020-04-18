#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long n,k,sp,ans;
map<vector<pair<long long,long long> >,long long> m;
long long a[N],f[N];
bool pr[N];
vector<pair<long long,long long> > tmp,tmb;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(long long i = 0;i < n;i++) cin >> a[i];

    for(long long i = 2;i < N;i++) pr[i] = true;

    for(long long i = 2;i < N;i++)
    {
        if(!pr[i]) continue;
        f[i] = i;
        for(long long j = 2;j*i < N;j++) pr[j*i] = false,f[j*i] = i;
    }

    for(long long i = 0;i < n;i++)
    {
        tmp.clear();
        for(long long j = f[a[i]];j;) 
        {
            long long x = 0;
            while(a[i]%j==0) a[i]/=j,x++;
            x%=k;
            if(x) tmp.push_back({j,x});
            int xj = j;
            j = f[a[i]];
            if(j==xj) break;
        }
        if(tmp.size()==0) sp++;
        else
        {
            sort(tmp.begin(),tmp.end());
            m[tmp]++;
        }
    }

    for(auto it = m.begin();it != m.end();it++)
    {
        tmp = it->first;
        long long x = it->second;
        tmb.clear();
        for(auto y : tmp) tmb.push_back({y.first,k-y.second});
        sort(tmb.begin(),tmb.end());
        if(tmb==tmp) ans+=x*(x-1LL);
        else ans+=x*m[tmb];
    }

    ans/=2LL;
    ans+=sp*(sp-1LL)/2LL;
    
    cout << ans;
}
