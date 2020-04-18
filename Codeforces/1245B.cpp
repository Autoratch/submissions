#include <bits/stdc++.h>
using namespace std;

int t,n;
int a,b,c;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b >> c >> s;
        int ans = 0;
        string t;
        t.resize(n);
        int i = 0;
        for(char x : s)
        {
            if(x=='R' and b) ans++,b--,t[i] = 'P';
            if(x=='P' and c) ans++,c--,t[i] = 'S';
            if(x=='S' and a) ans++,a--,t[i] = 'R'; 
            i++;
        }
        for(int i = 0;i < n;i++) if(t[i]!='P' and t[i]!='R' and t[i]!='S') 
        {
            if(a) t[i] = 'R',a--;
            else if(b) t[i] = 'P',b--;
            else if(c) t[i] = 'S',c--;
        }
        if(ans*2>=n) cout << "YES\n" << t << '\n';
        else cout << "NO\n";
    }
}