#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int i = 0;i < a;i++){ for(int j = 0;j < b;j++)
    {
        int x = max(abs(i-c),abs(j-d));
        cout << x << ' ';
    }cout << '\n'; }
}
