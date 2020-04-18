#include <bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
    int ab;
    cout << "? 0 0" << endl;
    cin >> ab;
    for(int i = 29;i >= 0;i--)
    {
        int x,y;
        cout << "? " << (a^(1 << i)) << ' ' << b << endl;
        cin >> x;
        cout << "? " << a << ' ' << (b^(1 << i)) << endl;
        cin >> y;
        if(x==y)
        {
            if(ab==1) a+=(1 << i),ab = x;
            else b+=(1 << i),ab = y;
        }
        else
        {
            if(x==-1) a+=(1 << i),b+=(1 << i);
        }
    }
    cout << "! " << a << ' ' << b << endl;
}
