#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k,n;
    cin >> k >> n;
    for(int i = 1;i <= n;i++)
    {
        if(i<n) cout << i << '\n';
        else cout << i+(k-i*(i+1)/2);
    }
}
