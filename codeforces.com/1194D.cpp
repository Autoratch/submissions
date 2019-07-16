#include <bits/stdc++.h>
using namespace std;

int t,n,k;
bool a[100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
   
    cin >> t;

    while(t--)
    {
        int a,b;
        cin >> a >> b;
        if(b%3!=0 or b>a)
        {
            if(a%3==0) cout << "Bob";
            else cout << "Alice";
        }
        else
        {
            a = (a-1)%(b+1)+1;
            if(a>=b+1-3)
            {
                if(a==b+1) cout << "Bob";
                else cout << "Alice";
            }
            else
            {
                if(a%3==0) cout << "Bob";
                else cout << "Alice";
            }
        }
        cout << '\n';
    }
}
