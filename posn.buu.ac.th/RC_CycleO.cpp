#include <bits/stdc++.h>
using namespace std;

int t,n;
map<int,int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        s.clear();
        for(int i = 0;i < n;i++) 
        {
            int x;
            cin >> x;
            s[x]++;
        }
        bool ok = true;
        for(auto it = s.begin();it != s.end();it++)
        {
            if(it==s.begin()) continue;
            auto itl = it,itr = it;
            itl--,itr++;
            if(itr==s.end()) continue;
            if(it->second<2) ok = false;
            if(it->first-itl->first>1 or itr->first-it->first>1) ok = false;
        }
        if(!ok or s.size()==1){ cout << "NO\n"; continue; }
        else cout << "YES\n";
    }
}
