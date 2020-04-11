#include <bits/stdc++.h>
using namespace std;

int m,n;
long long ans;
set<pair<int,long long> > s;

void upd(int x,long long k)
{
    auto its = s.lower_bound({x,-1});
    for(auto it = its;it != s.end();)
    {
        if(k-abs(x-it->first)>it->second) it = s.erase(it);
        else break;
    }
    its = s.lower_bound({x,-1});
    for(auto it = its;;)
    {
        if(it==s.begin()) break;
        auto it2 = it;
        it2--;
        if(k-abs(x-it2->first)>it2->second) s.erase(it2);
        else break;
    }
    s.insert({x,k});
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) s.insert({i,0});
    for(int i = 0;i < n;i++)
    {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        auto ilr = s.lower_bound({a,-1});
        auto ill = ilr; if(ilr!=s.begin()) ill--;
        if(ilr==s.end()) ilr--;
        long long resa = max(ill->second-abs(a-ill->first),ilr->second-abs(a-ilr->first))+c;
        auto irr = s.lower_bound({b,-1});
        auto irl = irr;  if(irr!=s.begin()) irl--;
        if(irr==s.end()) irr--;
        long long resb = max(irr->second-abs(b-irr->first),irl->second-abs(b-irl->first))+c;
        if(resa>resb-c) upd(b,resa);    
        if(resb>resa-c) upd(a,resb);
        ans = max(ans,max(resa,resb));
        cout << ans << '\n';
    }
}
