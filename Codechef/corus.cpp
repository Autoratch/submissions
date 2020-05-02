#include <bits/stdc++.h>
using namespace std;

const int N = 26;

int t,n,q;
string s;
int a[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(int i = 0;i < 26;i++) a[i] = 0;
        cin >> s;
        for(char c : s) a[c-'a']++;
        while(q--)
        {
            int x;
            cin >> x;
            int ans = 0;
            for(int i = 0;i < 26;i++) ans+=max(0,a[i]-x);
            cout << ans << '\n';
        }
    }
}
