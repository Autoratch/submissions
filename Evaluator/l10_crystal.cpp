#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
const int MOD = 10001;

long long c[N];

long long catalan(int n)
{
    long long res = 0;

    for(int cn = 2;cn <= n;cn++)
    {
        res = 0;
        for (int i = 0;i < cn;i++)
        {
            res += c[i]*c[cn-i-1];
            res%=MOD;
        }
        c[cn] = res;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    c[0] = 1; c[1] = 1;
    int n;

    cin >> n;

    if(n==1){ cout << '1'; return 0; }

    cout << catalan(n);
}
