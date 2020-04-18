#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,a,b,c;

    cin >> t;

    while(t--)
    {
        int x,y,z;
        cin >> a >> b >> c;
        x = a,y = b,z = c;
        int ans = 0;
        ans+=min(a,b/2)*3;
        int xb = b;
        b-=min(a,b/2)*2;
        ans+=min(b,c/2)*3;
        a = x,b = y,c = z;
        int ant = 0;
        ant+=min(b,c/2)*3;
        b-=min(b,c/2);
        ant+=min(a,b/2)*3;
        cout << max(ans,ant) << '\n';
/*
        a = min(a,b/2);
        b-=min(a,b/2)*2;
        b = min(b,c/2);
        y = min(y,z/2);
        
        cout << a*3+b*3 << '\n';*/
    }
}
