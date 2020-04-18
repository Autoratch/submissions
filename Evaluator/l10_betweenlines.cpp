#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    int x = 0;

    for(int i = 0;i < n-1;i++)
    {
        if(a[i]==13 and a[i+1]==10) x++;
    }

    cout << x+1 << '\n';
    x = 0;

    for(int i = 0;i < n;i++) if(a[i]==10) x++;
    cout << x+1 << '\n';
    x = 0;

    for(int i = 0;i < n;i++) if(a[i]==13) x++;
    cout << x+1 << '\n';
}
