#include <bits/stdc++.h>
using namespace std;

bool a[10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    string s;

    cin >> n >> s;

    for(char c : s)
    {
        if(c=='L')
        {
            int x = 0;
            while(a[x]) x++;
            a[x] = true;
        }
        else if(c=='R')
        {
            int x = 9;
            while(a[x]) x--;
            a[x] = true;
        }
        else a[c-'0'] = false;
    }

    for(int i = 0;i < 10;i++) if(a[i]) cout << '1'; else cout << '0';
}
