#include <bits/stdc++.h>
using namespace std;

int n,k,l,r;
vector<int> a;

bool solve(int x)
{
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        int tmp = a[i]/x;
        if(a[i]%x!=0) tmp++;
        ans+=tmp;
    }
    if(ans<=k) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    a.resize(n);

    for(int i = 0;i < n;i++){ cin >> a[i]; r = max(r,a[i]); }

    while(l<r)
    {
        int m = (l+r)/2;
        bool ok = solve(m);
        if(!ok) l = m+1;
        else r = m;
    }

    cout << l;
}
