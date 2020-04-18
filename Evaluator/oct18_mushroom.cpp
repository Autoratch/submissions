#include <bits/stdc++.h>
using namespace std;

int n;
double l,h;
multiset<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l >> h;

    for(int i = 0;i < n;i++)
    {
        int am,tmp;
        double x,y;
        cin >> am;
        while(am--){ cin >> tmp; s.insert(-tmp); }
        cin >> x >> y;
        double res = (x*h)/y+l;
        for(auto it = s.begin();it != s.end();it)
        {
            int tm = *it;
            tm = -tm;
            if(tm<res) break;
            it = s.erase(it);
        }
        cout << s.size() << '\n';
    }
}
