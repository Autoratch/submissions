#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;

int k,p;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> p;

    a[2] = 1;

    for(int i = 3;i <= k;i++)
    {
        a[i] = (a[i]+a[i-1])%p;
        if(i%2==0) a[i] = (a[i]+(a[i/2]))%p;
    }

    cout << a[k];
}
