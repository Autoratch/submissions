#include <bits/stdc++.h>
using namespace std;

int m;
map<int,int> res;

int lv(int x){ return log2(x); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m;

    while(m--)
    {
        char c;
        int a,b,w;
        cin >> c;
        if(c=='U')
        {
            cin >> a >> b >> w;
            while(lv(a)>lv(b)) res[a]+=w,a/=2;
            while(lv(b)>lv(a)) res[b]+=w,b/=2;
            while(a!=b) res[a]+=w,res[b]+=w,a/=2,b/=2;
        }
        else
        {
            cin >> a >> b;
            int ans = 0;
            while(lv(a)>lv(b)) ans+=res[a],a/=2;
            while(lv(b)>lv(a)) ans+=res[b],b/=2;
            while(a!=b) ans+=res[a]+res[b],a/=2,b/=2;
            cout << ans << '\n';
        }
    }
}
