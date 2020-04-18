#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,mn = INT_MAX;
int pa[N];
pair<int,int> a[N];

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        pa[i] = i;
    }

    sort(a+1,a+n+1);

    for(int i = 0;i < n-2;i++)
    {
        int x,y;
        cin >> x >> y;
        pa[root(x)] = pa[root(y)];
    }

    for(int i = 1;i < n;i++) if(root(a[i].second)!=root(a[i+1].second)) mn = min(mn,a[i+1].first-a[i].first);

    cout << mn;
}
