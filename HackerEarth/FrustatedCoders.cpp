#include <bits/stdc++.h>
using namespace std;

int n,s,m;
vector<int> a;
deque<int> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i],s+=a[i];

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    for(int i = 0;i < n;i++) 
    {
        if(!q.empty() and q.front()>a[i]) m+=a[i],q.pop_front();
        q.push_back(a[i]);
    }

    cout << s-m;
}
