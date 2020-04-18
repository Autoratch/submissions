#include <bits/stdc++.h>
using namespace std;

vector<pair<int,double> > a;

int main()
{
    for(int i = 1;i <= 11;i++)
    {
        double x;
        cin >> x;
        a.push_back({x,(double)(x*x*x*5+sqrt(abs(x)))});
    }
    reverse(a.begin(),a.end());
    for(auto x : a)
    {
        cout << "f(" << x.first << ") = ";
        if(x.second>400) cout << "MAGNA NIMIS!";
        else cout << fixed << setprecision(2) << x.second;
        cout << '\n';
    }

}
