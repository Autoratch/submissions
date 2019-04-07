#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;

    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        int y = i;
        if(y>(n+1)/2) y = (n+1)-y;
        for(int j = 0;j < (n+1)/2-y;j++) cout << ' ';
        if((n+1)/2==i) 
        {
            int x = (n-1)/2;
            for(int j = 0;j < x/2;j++) cout << "*^";
            if(x%2==1) cout << "*";
            cout << "N";
            if(x%2==1) cout << "*";
            for(int j = 0;j < x/2;j++) cout << "^*";
        }
        else
        {
           int x = i;
           if(x>(n+1)/2) x = (n+1)-x;
           x = (x*2-1);
           for(int j = 0;j < x/2;j++) cout << "*^";
           cout << "*";
        }
        cout << '\n';
    }

}
