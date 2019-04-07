#include <bits/stdc++.h>
using namespace std;

int n,x,a = INT_MAX,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        cin >> x >> b;
        if(b<=a)
        {
            cout << "0\n";
            a = b;
        }
        else
        {
            cout << b-a << '\n';
        }
    }
}
