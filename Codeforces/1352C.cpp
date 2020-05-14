#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n,k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int a = k/(n-1);
        if(k%(n-1)==0) a--;
        cout << k+a << '\n';
    }
}
