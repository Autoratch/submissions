#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,m,k;
int a[N];
vector<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);

    for(int i = 0;i < n;i++)
    {
        auto it = lower_bound(s.begin(),s.end(),a[i]+1-m);
        if(s.end()-it==k-1) continue;
        s.push_back(a[i]);
    }

    cout << n-s.size();
}
