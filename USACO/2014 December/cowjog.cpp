#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,ans;
long long t,x,y,a;
vector<long long> s;

int main()
{
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    cin >> n >> t; 
    for(int i = 1;i <= n;i++)
    {
        cin >> x >> y;
        a = t*y+x; a = -a;
        auto it = upper_bound(s.begin(),s.end(),a);
        if(it==s.end()) s.push_back(a);
        else *it = a;
    }
    cout << s.size();
}
