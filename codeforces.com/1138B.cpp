#include<bits/stdc++.h>
using namespace std ;

string a,b;
vector<int> t[4],s1,s2,s3,s4;
int n;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b;

    for(int i = 0;i < n;i++)
    {
        if(a[i]=='0' and b[i]=='0') t[0].push_back(i);
        else if(a[i]=='0' and b[i]=='1') t[1].push_back(i);
        else if(a[i]=='1' and b[i]=='0') t[2].push_back(i);
        else t[3].push_back(i);
    }

    for(int i = 0;i < t[1].size();i++) s1.push_back(t[1][i]);
    for(int i = 0;i < t[2].size();i++) s2.push_back(t[2][i]);
    for(int i = 0;i < t[3].size();i++)
    {
        if(s1.size()+s3.size()<=s2.size()+s4.size()) s3.push_back(t[3][i]);
        else s4.push_back(t[3][i]);
    }

    int tmpa = s1.size()+s3.size();
    int tmpb = s2.size()+s4.size();

    while(tmpb>tmpa and !s2.empty())
    {
        s3.push_back(s2[s2.size()-1]);
        s2.pop_back();
        tmpb--;
    }

    while(tmpa>tmpb and !s1.empty())
    {
        s4.push_back(s1[s1.size()-1]);
        s1.pop_back();
        tmpa--;
    }

    if(tmpa!=tmpb){ cout << "-1"; return 0; }

    for(int i = 0;i < t[0].size();i++)
    {
        if(s1.size()+s3.size()<=s2.size()+s4.size()) s3.push_back(t[0][i]);
        else s4.push_back(t[0][i]);
    }

    if(s1.size()+s3.size()!=s2.size()+s4.size()){ cout << "-1"; return 0; }

    for(int i = 0;i < s2.size();i++) cout << s2[i]+1 << ' ';
    for(int i = 0;i < s4.size();i++) cout << s4[i]+1 << ' ';
}
