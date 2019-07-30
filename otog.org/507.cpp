#include <bits/stdc++.h>
using namespace std;

const int N = 3e3;

int t,q;
string s;   

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s >> q;
        while(q--)
        {
            string x;
            cin >> x;
            int i = 0,j = 0;
            while(i<s.length() and j<x.length())
            {
                if(s[i]==x[j]) i++,j++;
                else i++;
            }
            if(j==x.length()) cout << "Yes";
            else cout << "No";
            cout << '\n';
        }
    }
}
