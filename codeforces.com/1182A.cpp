#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    if(n%2==1) cout << "0";
    else cout << (1 << (n/2));
}
