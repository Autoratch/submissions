#include <bits/stdc++.h>
using namespace std;

const long long N = 150000;

long long n;
long long a[N];
deque<long long> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);

    for(long long i = 0;i < n;i++) q.push_front(a[i]);

    long long ans = 0;

    while(q.size()>=5)
    {
        ans+=q.front()+q.back();
        q.pop_front(),q.pop_back();
        ans+=q.back();
        q.pop_front(),q.pop_back();
        ans+=q.back();
        q.pop_back();
    }

    while(!q.empty()) ans+=q.front(),q.pop_front();

    cout << ans;
}
