#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    int a,b,c,d;
    
    cin >> a >> b >> c >> d;

    if(a>c) swap(a,c),swap(b,d);

    cout << b-a+d-c-max(0,min(b,d)-c);
}
