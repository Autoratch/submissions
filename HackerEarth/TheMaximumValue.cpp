#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long k;
    cin >> k;
    long long a = 1,b = 1;
    while(true)
    {
        if(a+b>k){ cout << a+b; return 0; }
        long long c = a+b;
        a = b,b = c;
    }
}
