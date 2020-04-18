#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    s.insert(n);
    
    while(true)
    {
        n++;
        while(n%10==0) n/=10;
        if(s.find(n)!=s.end()) break;
        s.insert(n);
    }

    cout << s.size();
}
