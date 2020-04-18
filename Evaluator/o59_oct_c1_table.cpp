#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int s[301][5001],mn[301];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;

    while(k--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int a,b,c;
            cin >> a >> b >> c;
            s[a][b] = c; mn[a] = c;
            for(int i = 1;i <= n;i++) mn[a] = min(mn[a],s[a][i]);
        }
        else if(t==2)
        {
            int a,b;
            cin >> a >> b;
            for(int i = 1;i <= n;i++) s[a][i] = b;
            mn[a] = b;
        }
        else if(t==3)
        {
            int a,b;
            cin >> a >> b;
            cout << s[a][b] << '\n';
        }
        else 
        {
            int tmp = INT_MAX;
            for(int i = 1;i <= m;i++) tmp = min(tmp,mn[i]);
            cout << tmp << '\n';
        }
    }
}   
