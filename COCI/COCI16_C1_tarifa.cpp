#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,x,s = 0;
    cin >> x >> n;
    for(int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        s+=a;
    }
    cout << (n+1)*x-s;
}
