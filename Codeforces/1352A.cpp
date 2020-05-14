#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n;

    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> ans;
        while(n) ans.push_back(n%10),n/=10;
        int am = 0;
        for(int x : ans) if(x) am++;
        cout << am << '\n';
        int m = 1;
        for(int x : ans){ if(x) cout << x*m << ' '; m*=10; }
        cout << '\n';
    }
}
