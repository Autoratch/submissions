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
        cin >> s;
        int x = 0,y = 0;
        bool f = false;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i]=='/') f = !f;
            else if(!f) x = x*10+s[i]-'0';
            else y = y*10+s[i]-'0';
        }
        while(x!=1 or y!=1)
        {
            if(x<y)
            {
                swap(x,y);
                x-=y;
                cout << 'L';
            }
            else
            {
                x-=y;
                swap(x,y);
                cout << 'R';
            }
        }
        cout << '\n';
    }
}
