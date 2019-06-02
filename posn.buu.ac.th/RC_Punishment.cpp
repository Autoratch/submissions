#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int t,n;
int a[N];
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        int g;
        bool f = false,z = false;
        for(int i = 0;i < n;i++)
        {
            if(!a[i]) continue;
            if(!f) g = a[i],f = true;
            else g = __gcd(g,a[i]);
        }
        for(int i = 0;i < n;i++) if(!a[i]) z = true; else a[i]/=g;
        s.clear();
        for(int i = 0;i < n;i++) s.insert(a[i]);
        int mx = 0;
        for(int i = 0;i < n;i++) mx = max(mx,a[i]);
        if(s.size()<n and !z) mx++;
        s.erase(0);
        if((mx-s.size())%2==1) cout << "Alive\n";
        else cout << "Dead\n";
    }
}
