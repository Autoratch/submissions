#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int t,n;
long long k;
long long a[N];
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        bool ok = true;
        for(int i = 0;i < n;i++) cin >> a[i];
        s.clear();
        for(int i = 0;i < n;i++)
        {
            int id = 0;
            while(a[i])
            {
                if(a[i]%k>1) ok = false;
                else if(a[i]%k==1 and s.find(id)!=s.end()) ok = false;
                else if(a[i]%k==1) s.insert(id);
                if(!ok) break;
                a[i]/=k;
                id++;
            }
            if(!ok) break;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
