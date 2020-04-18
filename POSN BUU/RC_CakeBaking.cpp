#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[100001],mx;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        a[x]++;
        mx = max(mx,x);
    }

    cin >> q;

    while(q--)
    {
        int t,x;
        cin >> t >> x;
        if(t==2) cout << a[x] << '\n';
        else 
        {
            for(int i = x;i <= mx;i++) a[i-x]+=a[i],a[i] = 0;
            mx = min(mx,mx-x);
        }
    }
}
