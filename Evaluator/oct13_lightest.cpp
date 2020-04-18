#include <bits/stdc++.h>
using namespace std;

int n,m;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n+m;i++)
    {
        char c;
        cin >> c;
        if(c=='T')
        {
            int a,b;
            cin >> a >> b;
            q.push({a,b});
        }
        else
        {
            if(q.empty()) cout << "0\n";
            else{ cout << q.top().second << '\n'; q.pop(); }
        }
    }
}
