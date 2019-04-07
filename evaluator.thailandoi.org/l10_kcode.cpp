#include <bits/stdc++.h>
using namespace std;

string s,x = "UUDDLRLRBAS";
bool res[100][100];
int tmp = -1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    for(int i = 0;i < x.length();i++) for(int j = 0;j < s.length();j++)
    {
        if(x[i]!=s[j]) continue;
        else if(i==0) res[i][j] = true;
        else if(j) res[i][j]|=res[i-1][j-1];
    }

    for(int i = 0;i < x.length();i++)
    {
        if(res[i][s.length()-1]) tmp = i;
    }

    for(int i = tmp+1;i < x.length();i++) cout << x[i];
}
