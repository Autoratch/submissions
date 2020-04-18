#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int m,n,k;
vector<tuple<int,int,int> > s[N];
vector<pair<int,int> > q[N];
int a[N],ans[N];

void update(int idx,int val){ idx++; while(idx<N) a[idx]+=val,idx+=(idx & -idx); }

int read(int idx){ idx++; int val = 0; while(idx>0) val+=a[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        s[a].push_back({b,d,1});
        s[c+1].push_back({b,d,-1});
    }

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        q[a].push_back({b,i});    
    }

    for(int i = 0;i <= 1e5;i++)
    {
        for(int j = 0;j < s[i].size();j++)
        {
            int l,r,x; tie(l,r,x) = s[i][j];
            update(l,x);
            if(r+1<N) update(r+1,-x);
        }
        for(int j = 0;j < q[i].size();j++)
        {
            int x = q[i][j].first,id = q[i][j].second;
            ans[id] = read(x);
        }
    }

    for(int i = 0;i < m;i++) cout << ans[i] << '\n';
}
