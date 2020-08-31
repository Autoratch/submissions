#include <bits/stdc++.h>
using namespace std;

long long n,d;
long long ans1,ans2,ans3,ans4;
map<string,set<string> > m[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> d;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        for(int j = 0;j < 4;j++) 
        {
            string l = s;
            l[j] = 'X';
            m[0][l].insert(s);
        }
        for(int j = 0;j < 4;j++) for(int k = j+1;k < 4;k++)
        {
            string l = s;
            l[j] = l[k] = 'X';
            m[1][l].insert(s);
        }
        for(int j = 0;j < 4;j++)
        {
            string l = s;
            for(int k = 0;k < 4;k++) if(k!=j) l[k] = 'X';
            m[2][l].insert(s);
        }
    }
    for(auto it : m[0]) 
    {
        long long x = it.second.size();
        ans1+=x*(x-1)/2;
    }
    for(auto it : m[1])
    {
        long long x = it.second.size();
        ans2+=x*(x-1)/2;
    }
    for(auto it : m[2])
    {
        long long x = it.second.size();
        ans3+=x*(x-1)/2;
    }
    ans2-=ans1*3;
    ans3-=ans1*3+ans2*2;
    ans4 = n*(n-1)/2-ans1-ans2-ans3;
    if(d==1) cout << ans1;
    else if(d==2) cout << ans2;
    else if(d==3) cout << ans3;
    else cout << ans4;
}
