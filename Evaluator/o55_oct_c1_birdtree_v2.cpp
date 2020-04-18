#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while(n--)
    {
        string s;
        int x = 0,y = 0;
        cin >> s;
        int i = 0;
        while(s[i]!='/') x = (x*10)+s[i]-'0',i++;
        i++;
        while(i<s.length()) y = (y*10)+s[i]-'0',i++;
        while(x!=1 or y!=1)
        {
            int px = x,py = y;
            if(x>y) x = py,y = px-py,cout << 'R';
            else y = px,x = py-px,cout << 'L';
        }
        cout << '\n';
    }
}
