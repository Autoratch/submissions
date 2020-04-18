#include <bits/stdc++.h>
using namespace std;

int n;
map<long long,int> s,l;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    long long a = 0,x,st = 0;
    s[0] = 1,l[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        a+=x;
        if(s[a]) st = max((int)st,(int)l[a]+1);
        ans+=(long long)(i-st);
        s[a]++; l[a] = i;
    }
    cout << ans;
}
