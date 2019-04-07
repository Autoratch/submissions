#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

struct node
{
    int idx;
    int h;
};

int n,cnt;
int ln;
node res[N];
vector<pair<int,int> > ah;
set<pair<int,int> > ai;
int l[N],r[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> ln;

    for(int i = 0LL;i < n;i++)
    {
        cin >> res[i].idx >> res[i].h;
        ai.insert({res[i].idx,i});
        ah.push_back({res[i].h,i});
    }

    sort(ah.begin(),ah.end());

    for(int i = 0LL;i < n;i++)
    {
        int id = ah[i].second;
        auto it = ai.lower_bound(make_pair(res[id].idx,id));
        auto it2 = it; it2++;
        while(it2!=ai.end())
        {
            int cur = it2->second;
            int vid = res[id].h+abs(res[id].idx-res[cur].idx)+id,vc = res[cur].h+cur;
            if(vid<vc or (vid==vc and id<cur)){ r[cur] = -1LL; it2 = ai.erase(it2); }
            else break;
        }
        it2 = it; it2--;
        while(true)
        {
            int cur = it2->second;
            int vid = res[id].h+abs(res[id].idx-res[cur].idx)+id,vc = res[cur].h+cur;
            if(vid<vc or (vid==vc and id<cur)){ r[cur] = -1LL; it2 = ai.erase(it2); }
            else break;
            if(it2==ai.begin()) break;
            else it2--;
        }
    }

    for(auto it = ai.begin();it != ai.end();it++)
    {
        int cur = it->second;
        auto itp = it; if(it!=ai.begin()) itp--;
        auto itn = it; itn++;
        if(it==ai.begin()) l[cur] = 0LL;
        else
        {
            int prev = itp->second;
            int idc = res[cur].idx,idp = res[prev].idx,hc = res[cur].h+cur,hp = res[prev].h+prev;
            if(hc<hp) idc-=(hp-hc);
            else idp+=(hc-hp);
            l[cur] = idc-(idc-idp-1LL)/2LL;
            if((idc-idp)%2LL==0LL)
            {
                if(idc==idp){ if(cur>prev) l[cur]++; }
                else if(cur<prev) l[cur]--;
            }
            r[prev] = l[cur]-1LL;
        }
        if(itn==ai.end()) r[cur] = ln;
    }

    for(int i = 0LL;i < n;i++)
    {
        if(r[i]==-1LL) cout << "0\n";
        else cout << r[i]-l[i]+1LL << '\n';
    }
}
