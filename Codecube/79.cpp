#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,ans,cur = 1;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    
    a.resize(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    while(true)
    {
        bool f = true;
        for(int i = 1;i < n;i++) if(a[i]>a[i+1]) f = false;
        if(f){ cout << n-ans; return 0; }
        int idx;
        for(int i = 1;i <= n;i++) if(a[i]==cur) idx = i;
        if(a[idx]!=idx)
        {
            a.erase(a.begin()+idx);
            a.insert(a.begin()+cur,cur);
            ans++;
        }
        if(cur>n/2) cur = n+2-cur;
        else cur = n+1-cur;
    }
}
