#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int t,n,b;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int j = 1;j <= t;j++)
    {
        cin >> n >> b;
        for(int i = 0;i < n;i++) cin >> a[i];
        sort(a,a+n);
        int mx = 0;
        for(int i = 0;i < n;i++)
        {
            if(b>=a[i]) b-=a[i];
            else break;
            mx = i+1;
        }
        cout << "Case #" << j <<  ": " << mx << '\n';
    }
}
