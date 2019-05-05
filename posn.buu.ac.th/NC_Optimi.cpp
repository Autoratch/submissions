#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
const int MOD = 1e9 + 7;

int t,n;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    a[0] = 14,a[1] = 15,a[2] = 63;
//    cout << "14\n15\n63\n";
    for(int i = 3;i < N;i++) 
    {
        a[i] = (6LL*a[i-3])%MOD;
        a[i] = (a[i]+5LL*a[i-2])%MOD;
        a[i] = ((a[i]-2LL*a[i-1])%MOD+MOD)%MOD;
//        cout << a[i] << endl;
    }
//return 0;
    for(int i = 1;i <= t;i++)
    {
        cin >> n;
        cout << "Case #" << i << ": " << a[n] << '\n';
    }
}
