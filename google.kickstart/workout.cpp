#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n,k;
priority_queue<tuple<int,int,int> > q;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n >> k;
        for(int j = 1;j <= n;j++) cin >> a[j];
        while(!q.empty()) q.pop();
        for(int j = 1;j < n;j++) if(a[j+1]-a[j]>1) q.push({a[j+1]-a[j],1,a[j+1]-a[j]});
        while(k-- and !q.empty())
        {
            int a = get<0>(q.top()),b = get<1>(q.top()),c = get<2>(q.top()); q.pop();
            if(b+1==c) continue;
            b++;
            q.push({(c+b-1)/b,b,c});
        }
        cout << "Case #" <<  i << ": ";
        if(q.empty()) cout << "1\n";
        else cout << get<0>(q.top()) << '\n';
    }
}
