#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(x%2==0 and y%2==0)
        {
            for(int i = 1;i <= x;i++)
            {
                for(int j = 1;j <= y;j++) if(j%2==0) cout << "B"; else if(j+1==y and i==1) cout << "B"; else cout << "W";
                cout << '\n';
            }
        }
        else if(x%2==1 and y%2==1)
        {
            for(int i = 1;i <= x;i++)
            {
                for(int j = 1;j <= y;j++) if((i+j)%2==0) cout << "B"; else cout << "W";
                cout << '\n';
            }
        }
        else
        {
            for(int i = 1;i <= x;i++)
            {
                for(int j = 1;j <= y;j++) if(i==x and j==y) cout << "B"; else if((i+j)%2==0) cout << "B"; else cout << "W";
                cout << '\n';
            }
        }
    }
}
