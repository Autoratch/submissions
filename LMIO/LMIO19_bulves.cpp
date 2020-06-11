#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n;
long long a[N],ans,s;
priority_queue<long long> q;
vector<long long> v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i] = x-y+a[i-1];
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i]<0) ans+=-a[i],a[i] = 0;
        if(a[i]>a[n]) ans+=a[i]-a[n],a[i] = a[n];
        q.push(a[i]),q.push(a[i]),q.pop();
        s+=a[i];
    }
    while(!q.empty()) v.push_back(q.top()),q.pop();
    reverse(v.begin(),v.end());
    long long prev = 0;
    for(auto x : v) s-=(n--)*(x-prev),prev = x;
    cout << s+ans;
}
