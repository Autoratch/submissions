#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a,b;

    cin >> a >> b;

    if(a==9 and b==1) cout << "9 10";
    else if(b-a>1) cout << "-1";
    else if(b<a) cout << "-1";
    else if(a==b) cout << a << '0' << ' ' << b << '1';
    else cout << a << '9' << ' ' << b << '0';
}
