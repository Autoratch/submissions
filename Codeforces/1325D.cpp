#include <bits/stdc++.h>
using namespace std;

long long x,y,a,xx,yy;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> x >> y; xx = x,yy =y;
    if(x==0 and y==0){ cout << "0"; return 0; }
    if(x>y or (y-x)%2LL==1){ cout << "-1"; return 0; }
    if(x==y){ cout << "1\n" << x; return 0; }
    a = y-x;
    a/=2LL;
    if((x+a)!=(x^a)){  cout << "3\n" << x << ' ' << a << ' ' << a; }
    else{ x^=a; cout << "2\n" << x << ' ' << a; }
}
