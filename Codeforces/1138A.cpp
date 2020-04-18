#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    int a[n];

    for(int i = 0;i < n;i++) cin >> a[i];

    int t = a[0],c = 0;
    vector<int> x;

    for(int i = 0;i < n;i++)
    {
        if(a[i]==t)
        {
            c++;
        }
        else
        {
            t = a[i];
            x.push_back(c);
            c = 1;
        }
    }

    x.push_back(c);

    int ans = 0;

    for(int i = 0;i < x.size()-1;i++) ans = max(ans,min(x[i],x[i+1])*2);

    cout << ans;
}
