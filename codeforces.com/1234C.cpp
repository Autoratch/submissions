#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int t,n;
bool a[2][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;   
        string s;
        cin >> s;
        for(int i = 0;i < n;i++) a[0][i] = s[i]<='2';
        cin >> s;
        for(int i = 0;i < n;i++) a[1][i] = s[i]<='2';
        int x = 0,y = 0,t = 0;
        while(true)
        {
            if(x==1 and y==n-1)
            {
                if(!t and !a[x][y]) x--;
                else if(t and a[x][y]) x--;
                break;
            }
            if(t and a[x][y]) break;
            if(t) y++,t = 0;
            else if(a[x][y]) y++,t = 0;
            else x = 1-x,t = 1;
        }
        if(x==1 and y==n-1) cout << "YES\n";
        else cout << "NO\n";
    }
}
