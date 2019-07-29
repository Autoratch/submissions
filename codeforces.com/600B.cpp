#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,m;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());

    for(int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(a.begin(),a.end(),x);
        cout << it-a.begin() << ' ';
    }
}   
