#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 2;

int n,m,q;
int bl[N],need[N];
vector<int> wh[N];
int l[N],r[N];
vector<int> ask[N];
vector<tuple<int,int,int> > inp;
long long fw[N];

void update(int idx,long long val){ while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

long long read(int idx){ if(idx==0) return 0; long long val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> bl[i],wh[bl[i]].push_back(i);
    for(int i = 1;i <= n;i++) cin >> need[i];
    cin >> q;
    for(int i = 1;i <= q;i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        inp.push_back({l,r,k});
    }
    for(int i = 1;i <= n;i++) l[i] = 1,r[i] = q+1;
    while(true)
    {
        bool done = true;
        for(int i = 1;i <= n;i++) if(l[i]<r[i]) done = false,ask[(l[i]+r[i])/2].push_back(i);
        if(done) break;
        for(int i = 1;i <= m;i++) fw[i] = 0;
        for(int i = 1;i <= q;i++)
        {
            auto [ll,rr,k] = inp[i-1];
            if(ll<=rr) update(ll,k),update(rr+1,-k);
            else update(1,k),update(rr+1,-k),update(ll,k);
            for(int x : ask[i]) 
            {
                long long tmp = 0;
                for(int y : wh[x]){ tmp+=read(y); if(tmp>1e9) tmp = 1e9 + 1; }
                if(tmp>=need[x]) r[x] = i;
                else l[x] = i+1;
            }
            ask[i].clear();
        }
    }
    for(int i = 1;i <= n;i++) if(l[i]<=q) cout << l[i] << '\n'; else cout << "NIE\n";
}
