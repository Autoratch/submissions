#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 1;

int n;
pair<int,int> a[N];
vector<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        a[x-1].first = i;
    }

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        a[x-1].second = i;
    }
    
    sort(a,a+n);

    for(int i = 0;i < n;i++)
    {
        auto it = lower_bound(s.begin(),s.end(),a[i].second);
        if(it==s.end()) s.push_back(a[i].second);
        else *it = a[i].second;
    }
   
    cout << s.size();
}
