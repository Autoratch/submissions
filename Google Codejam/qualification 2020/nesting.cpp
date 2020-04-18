#include <bits/stdc++.h>
using namespace std;

const int N = 102;

int t;
string s;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int c = 0;c < t;c++)
    {
        cin >> s;
        for(int i = 0;i < N;i++) a[i] = b[i] = 0;
        int cur = 0;
        s = s+"0";
        int id = 0;
        for(char c : s)
        {
            int x = c-'0';
            while(cur>x) a[id]++,cur--;
            while(cur<x) b[id]++,cur++;
            id++;
        }
        cout << "Case #" << c+1 << ": ";
        id = 0;
        for(char c : s)
        {
            while(a[id]--) cout << ")";
            while(b[id]--) cout << "(";
            if(id<s.length()-1) cout << c;
            id++;
        }
        cout << '\n';
    }
}
