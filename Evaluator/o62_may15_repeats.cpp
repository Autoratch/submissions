#include <bits/stdc++.h>
using namespace std;

int n,k,ans;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> s;
    n = s.length();
    s = " "+s;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) 
    {
        int cnt = 0;
        if(i+j+j-1>n) continue;
        for(int x = i,y = i+j;x < i+j;x++,y++)
        {
            if(s[x]!=s[y]) cnt++;
        }
        ans+=(int)(cnt<=k);
    }
    cout << ans;
}
