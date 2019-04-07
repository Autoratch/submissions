#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<pair<pair<int,int>,int> > a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        a.resize(n);
        for(int i = 0;i < n;i++)
        {
            int v,t;
            cin >> v >> t;
            a[i] = {{t+m*1000/v,-v},i};
        }
        sort(a.begin(),a.end());
        for(int i = 0;i < n;i++) cout << a[i].second+1 << endl;
    }
}