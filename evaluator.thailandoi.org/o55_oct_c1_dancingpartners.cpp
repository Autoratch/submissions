#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;

int n,lst;
vector<int> res;
int dpl[N],dpr[N],h[N];
pair<int,int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;    

    for(int i = 0;i < n;i++)
    {
        int x,v;
        cin >> x >> v;
        if(x!=lst) res.push_back(x);
        h[res.size()-1] = max(h[res.size()-1],v);
        lst = x;
    }

    for(int i = 1;i <= res.size();i++)
    {
        dpl[i] = h[i-1];
        if(i>1) dpl[i] = max(dpl[i],dpl[i-1]-res[i-1]+res[i-2]);
    }

    for(int i = res.size()-1;i >= 0;i--)
    {
        dpr[i] = h[i];
        if(i<res.size()-1) dpr[i] = max(dpr[i],dpr[i+1]+res[i]-res[i+1]);
    }
    
    for(int i = 0;i < n;i++)
    {
        int x = a[i].first,y = a[i].second;
        auto it = upper_bound(res.begin(),res.end(),x);
        int idx = it-res.begin();
        int lft = (int)(-1e9),rgt = (int)(1e9);
        if(idx>0) lft = res[idx-1];
        if(idx<res.size()) rgt = res[idx];
        cout << max(dpl[idx]-x+lft,dpr[idx]+x-rgt)+y << '\n';
    }

}
