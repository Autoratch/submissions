#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int t,n;
deque<int> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        while(!q.empty()) q.pop_back();
        for(int i = 1;i <= n;i++)
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        int m = 0,a = 0,b = 0,now = 0;
        while(true)
        {
            if(q.empty()) break;
            m++;
            if(m%2==1)
            {
                int e = 0;
                while(!q.empty() and e<=now) e+=q.front(),q.pop_front();
                a+=e,now = e;
            }
            else
            {
                int e = 0;
                while(!q.empty() and e<=now) e+=q.back(),q.pop_back();
                b+=e,now = e;
            }
        }
        cout << m << ' ' << a << ' ' << b << '\n';
    }
}
