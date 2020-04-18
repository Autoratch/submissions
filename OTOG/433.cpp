#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;

string s;
int k;
int ans;
deque<int> q;
int sz;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> k;

    for(int i = 0;i < s.length();i++)
    {
        if(!q.empty() and q.front()<i) q.pop_front(),sz--;
        if(sz%2==1) s[i] = '+'+'-'-s[i];
        if(i+k-1>=s.length()) continue;
        if(s[i]=='+') continue;
        q.push_back(i+k-1);
        sz++;
        ans++;
        s[i] = '+';
    }

    bool f = false;

    for(char c : s) if(c=='-') f = true;

    if(f) cout << "IMPOSSIBLE";
    else cout << ans;
}
