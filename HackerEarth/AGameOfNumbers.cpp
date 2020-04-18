#include <bits/stdc++.h>
using namespace std;

const int N = 3e4;

int n,a[N],m[N],l[N];
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
            m[x] = i;
        }
        s.push({a[i],i});
    }

    while(!s.empty()) s.pop();

    for(int i = 0;i < n;i++) 
    {
        while(!s.empty() and s.top().first>a[i])
        {
            int x = s.top().second;
            s.pop();
            l[x] = i;
        }
        s.push({a[i],i});
    }

    for(int i = 0;i < n;i++)
    {
        int x = l[m[i]];
        if(m[i]==0 or x==0) cout << "-1";
        else cout << a[x];
        cout << ' ';
    }
}
