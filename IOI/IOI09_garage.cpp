#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int n,m,ans;
int rates[N],wei[N],slot[N];
priority_queue<int,vector<int>,greater<int> > q;
queue<int> car;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> rates[i],q.push(i);
    for(int i = 1;i <= m;i++) cin >> wei[i];
    for(int i = 0;i < m*2;i++)
    {
        int x;
        cin >> x;
        if(x>0) car.push(x);
        else q.push(slot[-x]);
        if(!q.empty() and !car.empty())
        {
            slot[car.front()] = q.top();
            q.pop(),car.pop();
        }
    }
    for(int i = 1;i <= m;i++) ans+=rates[slot[i]]*wei[i];
    cout << ans;
}
