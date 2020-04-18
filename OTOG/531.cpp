#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 1;

int n,q;
int a[N],s[N],ans[N],lst[N];
vector<pair<int,int> > qe[N];

void update(int idx,int val){ while(idx<=n) s[idx]+=val,idx+=(idx & -idx); }

int read(int idx){ int val = 0; while(idx>0) val+=s[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 0;i < q;i++)
    {
        int x,y;
        cin >> x >> y;
        qe[y].push_back({x,i});
    }

    for(int i = 1;i <= n;i++)
    {
        if(lst[a[i]]) update(lst[a[i]],-read(lst[a[i]])+read(lst[a[i]]-1));
        update(i,1);
        lst[a[i]] = i;
        for(pair<int,int> j : qe[i]) ans[j.second] = read(i)-read(j.first-1);
    }

    for(int i = 0;i < q;i++) cout << ans[i] << '\n';
}
