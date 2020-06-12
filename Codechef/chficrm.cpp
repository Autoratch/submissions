#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,a = 0,b = 0,c = 0;
        bool dead = false;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            if(x==5) a++;
            else if(x==10)  
            {
                if(!a) dead = true;
                else a--,b++;
            }
            else
            {
                if(b>=1) c++,b--;
                else if(a>=2) c++,a-=2;
                else dead = true;
            }
        }
        if(dead) cout << "NO\n";
        else cout << "YES\n";
    }
}
