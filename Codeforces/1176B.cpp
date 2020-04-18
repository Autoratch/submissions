#include <bits/stdc++.h>
using namespace std;

int t,n;
int a[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0;i < 3;i++) a[i] = 0;
        for(int i = 0;i < n;i++) 
        {
            int x;
            cin >> x;
            a[x%3]++;
        }
        int x = min(a[1],a[2])+a[0];
        int mn = min(a[1],a[2]);
        a[1]-=mn,a[2]-=mn;
        x+=a[1]/3+a[2]/3;
        cout << x << '\n';
    }
}
