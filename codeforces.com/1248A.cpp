#include <bits/stdc++.h>
using namespace std;

long long t,ae,ao,be,bo,n,m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        ae = 0,ao = 0,be = 0,bo = 0;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            if(x%2==0) ae++;
            else ao++;
        }
        cin >> m;
        for(int i = 0;i < m;i++)
        {
            int x;
            cin >> x;
            if(x%2==0) be++;
            else bo++;
        }
        cout << ao*bo+ae*be << '\n';
    }
}
