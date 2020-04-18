#include <bits/stdc++.h>
using namespace std;

int q;
string x;

bool isvow(char c)
{
    if(c=='a') return true;
    if(c=='e') return true;
    if(c=='i') return true;
    if(c=='o') return true;
    if(c=='u') return true;
    return false;
}

void solve()
{
    int sl = -1,el = x.length()-1,sr = 0,er = -1;
    for(int i = 0;i < x.length();i++)
    {
        if(isvow(x[i]))
        {
            if(sl==-1) sl = i;
        }
        else
        {
            if(sl!=-1){ el = i-1; break; } 
        }
    }
    for(int i = x.length()-1;i >= 0;i--)
    {
        if(isvow(x[i]))
        {
            if(er==-1) er = i;
        }
        else
        {
            if(er!=-1){ sr = i+1; break; }
        }
    }
    if(sl==sr){ cout << x << endl; return; }
    for(int i = 0;i < sl;i++) cout << x[i];
    for(int i = sr;i <= er;i++) cout << x[i];
    for(int i = el+1;i < sr;i++) cout << x[i];
    for(int i = sl;i <= el;i++) cout << x[i];
    for(int i = er+1;i < x.length();i++) cout << x[i];
    cout << endl;
}

int main()
{
    cin >> q;

    while(q--)
    {
        cin >> x;
        solve();
    }
}
