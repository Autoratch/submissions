#include <bits/stdc++.h>
using namespace std;

int c,n;
map<int,int> a,b;
vector<long long> s,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> c;
    while(c--)
    {
        cin >> n;
        a.clear(),b.clear(),s.clear(),t.clear();
        bool ok = true;
        long long mn = INT_MAX;
        for(int i = 1;i <= n;i++){ int x; cin >> x; a[x]++; mn = min(mn,(long long)x); }
        for(int i = 1;i <= n;i++){ int x; cin >> x; b[x]++; mn = min(mn,(long long)x); }
        for(auto it : a) if((a[it.first]+b[it.first])%2==1) ok = false;
        for(auto it : b) if((a[it.first]+b[it.first])%2==1) ok = false;
        if(!ok){ cout << "-1\n"; continue; }
        for(auto it : a) if(a[it.first]>b[it.first]) for(int i = 0;i < (a[it.first]-b[it.first])/2;i++) s.push_back(it.first);
        for(auto it : b) if(b[it.first]>a[it.first]) for(int i = 0;i < (b[it.first]-a[it.first])/2;i++) t.push_back(it.first);
        reverse(t.begin(),t.end());
        long long ans = 0;
        for(int i = 0;i < s.size();i++) ans+=min(min(s[i],t[i]),mn*2);
        cout << ans << '\n';
    }
}
    

