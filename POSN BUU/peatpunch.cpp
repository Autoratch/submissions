#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,q,p,a[N],res[N];
stack<pair<int,int> > s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        while(!s.empty() and s.top().first>a[i]) s.pop();
        if(s.empty()) p = 0;
        else p = max(s.top().second,a[i]-s.top().first);
        res[i] = p;
        s.push({a[i],p});
    }
    sort(res,res+n);
    while(q--)
    {
        int x;
        cin >> x;
        cout << n-(int)(upper_bound(res,res+n,x)-res) << '\n';
    }
}
