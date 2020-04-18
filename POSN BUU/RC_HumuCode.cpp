#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

vector<char> a;
vector<vector<char> > ans;
int num;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    getline(cin,s);

    for(char c : s)
    {
        a.push_back(c);
        if(c=='.') num++;
    }

    ans.resize(num);

    int x = 0;

    for(char c : a)
    {
        while(!ans[x].empty() and ans[x].back()=='.') x++,x%=num;
        if(c==' ') c = '_';
        ans[x].push_back(c);
        x++,x%=num;
    }
    
    for(int i = 0;i < num;i++)
    {
        for(char c : ans[i]) cout << c;
        cout << '\n';
    }
}
