#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,l,k;
deque<pair<int,int> > q;
set<int> s;
unordered_map<int,int> ma,ba;
pair<int,int> in[N];
int fw[N];
int ans;

void update(int idx,int val){ while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

int read(int idx){ int val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l >> k;
    for(int i = 0;i < n;i++){ int a,b; cin >> a >> b; in[i] = {a,b}; s.insert(b); }
    int id = 1;
    for(int x : s) ma[x] = id++,ba[id-1] = x; 
    for(int i = 0;i < n;i++)
    {
        int a = in[i].first,b = in[i].second;
        while(!q.empty() and a-q.front().first>l)
        {
            update(ma[q.front().second],-1);
            q.pop_front();
        }
        q.push_back({a,b});
        int mab = ma[b];
        update(mab,1);
        for(int j = mab-k;j <= mab;j++)
        {
            int l;
            for(l = j;ba[l]-ba[j]<=k and l<=s.size();l++);
            l--;
            if(l<mab) continue;
            ans = max(ans,read(l)-read(j-1));
        }
    }
    cout << ans;
}
