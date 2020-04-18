#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int t,n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        sort(a,a+n);
        bool f = false;
        for(int i = 0;i < n-1;i++) if(a[i]+1==a[i+1]) f = true;
        cout << (int)f+1 << '\n';
    }
}
