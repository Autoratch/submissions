#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int t,n,k;
int a[N],b[N];
vector<tuple<int,int,int> > ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;i++) cin >> a[i],b[a[i]] = i;
        ans.clear();
        bool fcked = false;
        for(int i = 1;i <= n;i++) if(a[i]!=i) 
        {
            int x = i,y = a[i],z = a[a[i]];
            if(x==z)
            {
                z = -1;
                for(int j = 1;j <= n;j++) if(a[j]!=j and j!=x and j!=y and z==-1) z = a[j];
                if(z==-1) fcked = true;
            }
            int lx = b[x],ly = b[y],lz = b[z];
            ans.push_back({lx,ly,lz});
            a[ly] = x,a[lz] = y,a[lx] = z;
            b[a[ly]] = ly,b[a[lz]] = lz,b[a[lx]] = lx;
        }
        if(ans.size()>k) cout << "-1\n";
        else if(fcked) cout << "-1\n";
        else 
        {
            cout << ans.size() << '\n';
            for(auto x : ans) cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << '\n';
        }
    }
}
