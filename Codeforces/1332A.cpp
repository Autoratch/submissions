#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,d,x,y,x1,y1,x2,y2;
        cin >> a >> b >> c >> d >>  x >>  y >> x1 >> y1 >> x2 >> y2;
        x-=a,x+=b;
        y-=c,y+=d;
        if(x<x1 or x>x2 or y<y1 or y>y2 or (x1==x2 and (a or b)) or (y1==y2 and (c or d))) cout << "No";
        else cout << "Yes";
        cout << '\n';
    }
}
