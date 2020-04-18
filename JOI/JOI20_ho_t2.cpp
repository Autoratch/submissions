#include <bits/stdc++.h>
using namespace std;

int n,k,ans = INT_MAX;
string s;
vector<int> a,b,c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> s;
    for(int i = 0;i < n;i++)
    {
        char ch = s[i];
        if(ch=='J') a.push_back(i);
        else if(ch=='O') b.push_back(i);
        else c.push_back(i);
    }
    for(int i = 0;i+k-1 < a.size();i++)
    {
        int x = a[i+k-1];
        auto ib = upper_bound(b.begin(),b.end(),x);
        if((int)(b.end()-ib)<k) break;
        ib+=k-1;
        x = *ib;
        auto ic = upper_bound(c.begin(),c.end(),x);
        if((int)(c.end()-ic)<k) break;
        ic+=k-1;
        ans = min(ans,*ic-a[i]+1-(k*3));
    }
    if(ans==INT_MAX) ans = -1;
    cout << ans;
}
