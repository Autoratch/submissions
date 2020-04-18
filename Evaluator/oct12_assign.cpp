#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a,b;

    cin >> a >> b;
    
    int x = 0,y = 0,p = 0,q = 0,t = 0;
    bool va = false,pa = false;
    vector<string> ans;

    while(x<a.length() and y<b.length())
    {
        char xx = a[x],yy = b[y]; 
        if(va) 
        {
            if(!pa and yy=='('){ cout << "no"; return 0; }
            if(!pa)
            {
                if(yy>='1' and yy<='9'){ ans.back()+=yy; y++; }
                else va = false,x++;
            }
            else
            {
                if(yy=='(') t++;
                else if(yy==')'){ t--; if(t==0) va = pa = false,x++; }
                ans.back()+=yy;
                y++;
            }
            continue;
        }
        if(xx=='(')
        {
            if(yy!=xx){ cout << "no"; return 0; }
            p++,q++; x++,y++;
        }
        else if(xx==')')
        {
            if(yy!=xx){ cout << "no"; return 0; }
            p--,q--; x++,y++;
        }
        else if(xx>='A' and xx<='Z')
        {
            va = true;
            t = 0;
            pa = false;
            if(yy=='(') pa = true;
            ans.push_back("");
        }
        else if(xx!=yy){ cout << "no"; return 0; }
        else x++,y++;
    }

    if(x!=a.length() or y!=b.length() or p or q){ cout << "no"; return 0; }

    for(string x : ans) cout << x << '\n';
}
