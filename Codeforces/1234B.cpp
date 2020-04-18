#include <bits/stdc++.h>
using namespace std;

int n,k;
set<int> s;
deque<int> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(s.find(x)==s.end()) 
        {
            q.push_front(x);
            if(q.size()>k) s.erase(q.back()),q.pop_back();
            s.insert(x);
        }
    }

    cout << q.size() << '\n';
    for(int x : q) cout << x << ' ';
}
