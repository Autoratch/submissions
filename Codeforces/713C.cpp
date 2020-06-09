#include <bits/stdc++.h>
using namespace std;

const long long N = 3001;

long long n;
long long a[N],s;
priority_queue<long long> q;
vector<long long> v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(long long i = 1;i <= n;i++) cin >> a[i],a[i]-=i-1,s+=a[i];
    for(long long i = 1;i <= n;i++) q.push(a[i]),q.push(a[i]),q.pop();
    while(!q.empty()) v.push_back(q.top()),q.pop();
    reverse(v.begin(),v.end());
    long long prev = 0;
    for(long long x : v) s-=(n--)*(x-prev),prev = x;
    cout << s;
}
