#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
vector<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        s.push_back(b-a+d);
    }

    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());

    for(int i = 0;i < k;i++) ans = max(ans,ans+s[i]);

    cout << m-1-ans;
}
