#include <bits/stdc++.h>
using namespace std;

const int N = 51;

int t,n;
string s[N],pre,suf;
vector<string> mid;
bool as[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int tt = 1;tt <= t;tt++)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> s[i],as[i] = false;
        int id = 0;
        bool out = false;
        pre = "",suf = "";
        mid.clear();
        while(true)
        {
            char now = ' ';
            for(int i = 1;i <= n;i++)
            {    
                if(as[i]) continue;
                else if(id>=s[i].length()) continue;
                else if(s[i][id]=='*'){ as[i] = true; continue; }
                if(now!=' '){ if(now!=s[i][id]){ out = true; break; } }
                else now = s[i][id];
            }
            if(now==' ') break;
            if(out) break;
            pre+=now;
            id++;
        }
        cout << "Case #" << tt << ": ";
        if(out){ cout << "*\n"; continue; }
        for(int i = 1;i <= n;i++) as[i] = false;
        id = 0;
        while(true)
        {
            char now = ' ';
            for(int i = 1;i <= n;i++)
            {
                if(as[i]) continue;
                else if(s[i].length()-1-id<0) continue;
                else if(s[i][s[i].length()-1-id]=='*'){ as[i] = true; continue; }
                if(now!=' '){ if(now!=s[i][s[i].length()-1-id]){ out = true; break; } }
                else now = s[i][s[i].length()-1-id];
            }
            if(now==' ') break;
            if(out) break;
            suf = now+suf;
            id++;
        }
        if(out){ cout << "*\n"; continue; }
        string ans = pre;
        for(int i = 1;i <= n;i++) for(char c : s[i]) if(c!='*') ans+=c;
        cout << ans+suf << '\n';
    }
}
