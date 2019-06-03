#include <bits/stdc++.h>
using namespace std;

int t,n;
deque<long long> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        while(!q.empty()) q.pop_back();
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        int ans = 0;
        while(q.size()>1)
        {
            if(q.front()==q.back()) q.pop_front(),q.pop_back();
            else
            {
                if(q.size()==2){ ans++; break; }
                int x = q.front(),y = q.back(),z;
                q.pop_front(),q.pop_back();
                if(x>y) z = q.back(),q.pop_back(),y+=z;
                else z = q.front(),q.pop_front(),x+=z;
                q.push_front(x),q.push_back(y);
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
