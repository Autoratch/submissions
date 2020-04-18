#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set<string> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    if(n%2==0){ cout << "NOT POSSIBLE"; return 0; }

    if(s.substr(1,n/2)==s.substr(1+n/2,n/2)) ans.insert(s.substr(1,n/2));

    bool sk = false,bm = true;

    for(int i = 0,j = n/2;i < n/2 and j < n;)
    {
        if(s[i]!=s[j]) 
        {
            if(sk){ bm = false; break; }
            else j++,sk = true;
        }
        else i++,j++;
    }

    if(bm) ans.insert(s.substr(0,n/2));

    sk = false,bm = true;

    for(int i = 0,j = n/2+1;i < n/2+1 and j < n;)
    {
        if(s[i]!=s[j]) 
        {
            if(sk){ bm = false; break; }
            else i++,sk = true;
        }
        else i++,j++; 
    }

    if(bm) ans.insert(s.substr(n/2+1,n/2));

    if(ans.size()==0) cout << "NOT POSSIBLE";
    else if(ans.size()>1) cout << "NOT UNIQUE";
    else cout << *ans.begin();
}
