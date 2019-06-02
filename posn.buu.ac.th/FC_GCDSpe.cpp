#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
int a[100000],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++) for(int j = i;j < n;j++)
    {
        int g = a[i];
        for(int k = i;k <= j;k++) g = __gcd(g,a[k]);
        if(g==1) ans++;
    }
cout << ans;
}
