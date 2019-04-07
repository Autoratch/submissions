#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m;

    cin >> n >> m;

    vector<int> a(n);

    for(int i = 0;i < n;i++){ cin >> a[i]; if(i) a[i]+=a[i-1]; }

    for(int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(a.begin(),a.end(),x);
        cout << it-a.begin() << endl;
    }
}
