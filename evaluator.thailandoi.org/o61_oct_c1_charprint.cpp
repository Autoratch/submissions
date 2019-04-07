#include <bits/stdc++.h>
using namespace std;

bool t;
string a,b;
vector<int> id[26];
int cur[26];
long long ans,s[300001];

void update(int idx,long long val)
{
    while(idx<=a.length()) 
    {
        s[idx]+=val;
        idx+=(idx & -idx);
    }
}

long long read(int idx)
{
    long long val = 0;
    while(idx>0)
    {
        val+=s[idx];
        idx-=(idx & -idx);
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t >> a >> b;

    for(int i = 0;i < a.length();i++) id[a[i]-'a'].push_back(i+1);

    if(!t)
    {
        for(int i = 0;i < b.length();i++)
        { 
            if(id[b[i]-'a'].size()<=cur[b[i]-'a']){ cout << "-1"; return 0; } 
            ans+=id[b[i]-'a'][cur[b[i]-'a']]; 
            cur[b[i]-'a']++; 
        }
    }
    else
    {
        for(int i = 0;i < a.length();i++) update(i+1,1);
        for(int i = 0;i < b.length();i++)
        {
            if(id[b[i]-'a'].size()<=cur[b[i]-'a']){ cout << "-1"; return 0; }
            int idx = id[b[i]-'a'][cur[b[i]-'a']];
            cur[b[i]-'a']++;
            ans+=read(idx);
            update(idx,-1);
        }
    }

    cout << ans;
}
