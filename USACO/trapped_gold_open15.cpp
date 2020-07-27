#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

pair<int,int> st[N];
int n,s[N],p[N],ans;
int l[N],r[N];
bool ok[N];

int main()
{
    freopen("trapped.in","r",stdin);
    freopen("trapped.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> s[i] >> p[i],l[i] = i,r[i] = i+1;
    for(int i = 1;i <= n;i++) st[i] = {p[i],s[i]};
    sort(st+1,st+n+1);
    for(int i = 1;i <= n;i++) p[i] = st[i].first,s[i] = st[i].second;
    for(int i = 1;i < n;i++) 
    {
        while(true)
        {
            bool out = true;
            if(p[r[i]]-p[l[i]]>s[l[i]]) l[i]--,out = false;
            if(l[i]<1 or ok[l[i]]){ ok[i] = true; break; }
            if(p[r[i]]-p[l[i]]>s[r[i]]) r[i]++,out = false;
            if(r[i]>n){ ok[i] = true; break; } 
            if(out) break;
        }
        if(!ok[i]) ans+=p[i+1]-p[i];
    }
    cout << ans;
}
