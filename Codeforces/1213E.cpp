#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    string x,yy;
    
    cin >> n >> x >> yy;

    char a = x[0],b = x[1],c = yy[0],d = yy[1];
    string s[6] = {"abc","acb","bac","bca","cab","cba"};
    string y1 = "dd",y2 = "dd";
    for(int i = 0;i < 6;i++)
    {
        if(s[i][0]==a and s[i][1]==b) continue;
        if(s[i][0]==c and s[i][1]==d) continue;
        if(s[i][1]==a and s[i][2]==b) continue;
        if(s[i][1]==c and s[i][2]==d) continue;
        y1 = s[i];
        if(s[i][2]==a and s[i][0]==b) continue;
        if(s[i][2]==c and s[i][0]==d) continue;
        y2 = s[i];
        break;
    }

    cout << "YES\n";

    if(a!=b and c!=d)
    {
        if(y1=="dd") cout << "NO";
        else for(int i = 0;i < 3;i++) for(int j = 0;j < n;j++) cout << y1[i];
    }
    else
    {
        if(y2=="dd") cout << "NO";
        for(int i = 0;i < n;i++) cout << y2;
    }
}