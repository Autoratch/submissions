#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int q;
string a,b;
bool dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> q;

    while(q--)
    {
        string s;
        cin >> s;
        dp[0][0] = true;
        for(int i = 0;i < s.length();i++)
        {
            for(int x = 0;x <= i+1;x++) 
            {
                int y = i+1-x;
                if(x>a.length() or y>b.length()) continue;
                if(x>0 and dp[x-1][y] and a[x-1]==s[i]) dp[x][y] = true;
                else if(y>0 and dp[x][y-1] and b[y-1]==s[i]) dp[x][y] = true;
                else dp[x][y] = false;
//                cout << x << ' ' << y << ' ' << dp[x][y] << endl;
            }
        }
        if(dp[a.length()][b.length()]) cout << "Yes\n";
        else cout << "No\n";
    }
}
