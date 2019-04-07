#include <bits/stdc++.h>
using namespace std;

int t,n,k;
vector<pair<int,int> > a;
int l,r;
set<int> s;

bool solve(int x)
{
    int cur = 0,tmp = 0;
    s.clear();
    for(int i = 0;i < n;i++)
    {
        if(a[i].first>x) return false;
        auto it = s.find(a[i].second);
        if(cur+a[i].first>x or it!=s.end())
        {
            s.clear();
            tmp++;
            cur = a[i].first;
        }
        else cur+=a[i].first;
        s.insert(a[i].second);
    }
    if(cur) tmp++;
    if(tmp>k) return false;
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        a.resize(n);
        for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
        l = 0; r = 1e8 + 1;
        while(l<r)
        {
            int m = (l+r)/2;
            bool ok = solve(m);
            if(!ok) l = m+1;
            else r = m;
        }
        if(l==1e8 + 1) l = -1;
        cout << l << '\n';
    }
}
