#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n;
int a[N],l[N],r[N];
stack<pair<int,int> > s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        while(!s.empty() and s.top().first<a[i])
        {
            int x = s.top().second;
            s.pop();
            r[x] = i-x;
        }
        s.push({a[i],i});
    }

    while(!s.empty())
    {
        int x = s.top().second;
        s.pop();
        r[x] = n-x;
    }

    for(int i = n-1;i >= 0;i--)
    {
        while(!s.empty() and s.top().first<a[i])
        {
            int x = s.top().second;
            s.pop();
            l[x] = x-i;
        }
        s.push({a[i],i});
    }

    while(!s.empty())
    {
        int x = s.top().second;
        s.pop();
        l[x] = x+1;
    }

    for(int i = 0;i < n;i++) cout << l[i]+r[i]-1 << ' ';
}
