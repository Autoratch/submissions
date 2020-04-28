#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int m,n;
vector<pair<int,int> > a;
int tmp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= n;i++)
    {
        int am,sum = 0;
        cin >> am;
        for(int j = 0;j < am;j++){ int x; cin >> x; sum+=x; tmp[j] = x; }
        int ll = 0,rr = sum;
        for(int j = 0;j < am;j++)
        {
            rr-=tmp[j];
            int l = ll+tmp[j],r = m-rr-tmp[j]+1;
            if(r<=l) a.push_back({r,l});
            ll+=tmp[j];
        }
    }
    sort(a.begin(),a.end());
    int now = 0,ans = 0;
    for(auto [x,y] : a) 
    {
        if(now<x) now = y,ans+=y-x+1;
        else if(y>now) ans+=y-now,now = y;
    }
    cout << ans;
}
