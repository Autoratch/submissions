#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int y = x;
    int a = 0;
    while(y) y/=2,a++;
    cout << "2 3\n" << (x|(1 << a)) << ' ' << x << ' ' << 0 << '\n' << (1 << a) << ' ' << (x|(1 << a)) << ' ' << x << endl;
}
