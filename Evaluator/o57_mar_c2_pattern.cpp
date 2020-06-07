#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,q;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> s;
    while(q--)
    {
        int m;
        string t;
        cin >> m >> t;
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++) 
            {
                if(i+j>=n) break;
                if(t[j]!='?' and s[i+j]!=t[j]) break;
                if(j==m-1) ans++;
            }
        }
        cout << ans << '\n';
    }
}
