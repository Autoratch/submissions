#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int> > q;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(!q.empty() and x>q.top()) ans+=x-q.top(),q.pop(),q.push(x),q.push(x);
        else q.push(x);
    }
    cout << ans;
}
