#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int l,r;

    cin >> l >> r;

    for(int i = l;i <= r;i++)
    {
        int tmp = i;
        string s;
        while(tmp) s+=(tmp%10+'0'),tmp/=10;
        sort(s.begin(),s.end());
        bool f = true;
        for(int j = 0;j < s.size()-1;j++) if(s[j]==s[j+1]) f = false;
        if(f){ cout << i; return 0; }
    }

    cout << "-1";
}
