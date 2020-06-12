#include <bits/stdc++.h>
using namespace std;

int t,n;
deque<int> o,e;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n*n;i++) if(i%2) o.push_back(i); else e.push_back(i);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++) if((i+j)%2==0) cout << o.front() << ' ',o.pop_front(); else cout << e.front() << ' ',e.pop_front();
            cout << '\n';
        }
    }
}
