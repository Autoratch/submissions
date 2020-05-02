#include <bits/stdc++.h>
using namespace std;

int t,x,y;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> x >> y >> s;
        int id = 0,ans = -1;
        for(char c : s)
        {
            if(c=='N') y++;
            else if(c=='S') y--;
            else if(c=='E') x++;
            else x--;
            id++;
            if(abs(x)+abs(y)<=id){ ans = id; break; }
        }
        cout << "Case #" << i << ": ";
        if(ans==-1) cout << "IMPOSSIBLE";
        else cout << ans;
        cout << '\n';
    }
}
