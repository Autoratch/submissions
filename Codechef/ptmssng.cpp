#include <bits/stdc++.h>
using namespace std;

int t,n;
map<int,int> x,y;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n; n*=4,n--;
        x.clear(),y.clear();
        while(n--)
        {
            int a,b;
            cin >> a >> b;
            x[a]++,y[b]++;
        }
        for(auto it : x) if(it.second%2==1) cout << it.first << ' ';
        for(auto it : y) if(it.second%2==1) cout << it.first << '\n';
    }
}
