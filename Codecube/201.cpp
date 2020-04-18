#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0 and b==0 and c==0){ cout << "YES\n"; continue; }
        if(a and b and c){ cout << "YES\n"; continue; }
        if(!a and !b){ if(c==1) cout << "YES\n"; else cout << "NO\n"; continue; }
        if(!b and !c){ if(a==1) cout << "YES\n"; else cout << "NO\n"; continue; } 
        if(!a and !c){ if(b==1) cout << "YES\n"; else cout << "NO\n"; continue; }
        if(!a){ if(b>1) cout << "NO\n"; else cout << "YES\n"; continue; }
        if(!b){ if(c>1) cout << "NO\n"; else cout << "YES\n"; continue; }
        if(!c){ if(a>1) cout << "NO\n"; else cout << "YES\n"; continue; }
    }
}
