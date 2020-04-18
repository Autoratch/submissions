#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<long long,long long>,int>
#define x first
#define h second

const int N = 1e5;

int n;
long long l,a,b;
set<pii> s,t;
long long ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l;

    for(int i = 0;i < n;i++)
    {
        cin >> a >> b;
        b+=(long long)i;
        s.insert({{a,b},i});
    }
    
    auto it = s.begin(),it2 = s.begin();
    it2++;
    
    long long ci,cx,ch,ni,nx,nh,sp;

    while(it2!=s.end())
    {
        if(it==it2){ it2++; continue; }
        ci = it->second,cx = it->first.first,ch = it->first.second;
        ni = it2->second,nx = it2->first.first,nh = it2->first.second;
        sp = nx-cx-1LL;
        if(nh-ch>sp+1 or (nh-ch==sp+1 and ci<ni)) it2 = s.erase(it2);
        else it++;
    }

    for(auto it = s.begin();it != s.end();it++) t.insert({{-it->first.first,it->first.second},it->second});
    
    it = t.begin(),it2 = t.begin();
    it2++;

    while(it2!=t.end())
    {
        if(it==it2){ it2++; continue; }
        ci = it->second,cx = it->first.first,ch = it->first.second;
        ni = it2->second,nx = it2->first.first,nh = it2->first.second;
        sp = nx-cx-1LL;
        if(nh-ch>sp+1 or (nh-ch==sp+1 and ci<ni)) it2 = t.erase(it2);
        else it++;
    }

    s.clear();
    for(auto it = t.begin();it != t.end();it++) s.insert({{-it->first.first,it->first.second},it->second});

    for(auto it = s.begin();it != s.end();it++)
    {
        auto it2 = it; it2++;
        ci = it->second,cx = it->first.first,ch = it->first.second;
        ans[ci]++;
        if(it==s.begin()) ans[ci]+=cx;
        if(it2==s.end())
        {
            ans[ci]+=l-cx;
            break;
        }
        ni = it2->second,nx = it2->first.first,nh = it2->first.second;
        sp = nx-cx-1LL;
        if(ch<nh)
        {
            ans[ci]+=nh-ch;
            if(nh-ch==sp+1) ans[ci]--;
            sp-=nh-ch;
            ans[ci]+=sp/2LL,ans[ni]+=sp/2LL;
            if(sp%2LL==1LL) 
            {
                if(ci<ni) ans[ci]++;
                else ans[ni]++;
            }
        }
        else
        {
            ans[ni]+=ch-nh;
            if(ch-nh==sp+1) ans[ni]--;
            sp-=ch-nh;
            ans[ci]+=sp/2LL,ans[ni]+=sp/2LL;
            if(sp%2LL==1LL)
            {
                if(ci<ni) ans[ci]++;
                else ans[ni]++;
            }
        }
    }

    for(int i = 0;i < n;i++) cout << ans[i] << '\n';
}
