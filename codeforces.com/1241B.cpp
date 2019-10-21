#include <bits/stdc++.h>
using namespace std;

const int N = 26;

int cs;
string a,b;
set<char> s,t;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> cs;

    while(cs--)
    {
        cin >> a >> b;
        s.clear(),t.clear();
        for(char c : a) s.insert(c);
        for(char c : b) t.insert(c);
        for(int i = 0;i < 26;i++) dp[i] = 0;
        for(char c : s) dp[c-'a']++;
        for(char c : t) dp[c-'a']++;
        bool f = false;
        for(int i = 0;i < 26;i++) if(dp[i]==2) f = true;
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
}
