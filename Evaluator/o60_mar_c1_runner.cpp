#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int n,m;
pair<long long,long long> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;

    for(int i = 0;i < m;i++)
    {
        long long x,l,r;
        cin >> x >> l >> r;
        int cnt = 0;
        for(int j = 0;j < n;j++)
        {
            long long st = a[j].first,v = a[j].second;
            if(x+st*v>=l*v and x+st*v<=r*v) cnt++;
        }
        cout << cnt << '\n';
    }
}
