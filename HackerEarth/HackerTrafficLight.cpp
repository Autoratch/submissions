#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,k,now,ans;
char a[N];
deque<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        while(!q.empty() and i-q.front().second>=k) now = ((now-q.front().first)%3+3)%3,q.pop_front();
        int cur;
        if(a[i]=='R') cur = 1;
        else if(a[i]=='Y') cur = 2;
        else cur = 0;
        cur+=now;
        cur%=3;
        int pr = 3-cur;
        pr%=3;
        ans+=pr;
        now+=pr;
        now%=3;
        q.push_back({pr,i});
    }

    cout << ans;
}
