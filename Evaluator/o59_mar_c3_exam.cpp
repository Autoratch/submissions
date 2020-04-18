#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n,m,a[N],s[N];
map<int,int> lst;
vector<pair<int,int> > q[N];
int ans[N];

void update(int idx,int val){ while(idx<N) s[idx]+=val,idx+=(idx & -idx); }

int read(int idx){ int val = 0; while(idx>0) val+=s[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;

    for(int i = 1;i <= n;i++) cin >> a[i];

    cin >> m;

    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        x++,y++;
        q[y].push_back({x,i});
    }

    for(int i = 1;i <= n;i++)
    {
        if(lst[a[i]]) update(lst[a[i]],-1);
        update(i,1);
        lst[a[i]] = i;
        for(int j = 0;j < q[i].size();j++) ans[q[i][j].second] = (i-q[i][j].first+1)-(read(i)-read(q[i][j].first-1));
    }

    for(int i = 0;i < m;i++) cout << ans[i] << '\n';
}
