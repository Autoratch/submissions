#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(x==1) a++;
        else b++;
    }

    if(!a or !b)
    {
        for(int i = 0;i < a;i++) cout << "1 ";
        for(int i = 0;i < b;i++) cout << "2 ";
    }
    else
    {
        cout << "2 1 ";
        for(int i = 1;i < b;i++) cout << "2 ";
        for(int i = 1;i < a;i++) cout << "1 ";
    }
}
