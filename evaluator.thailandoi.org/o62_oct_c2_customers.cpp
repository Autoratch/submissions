#include <bits/stdc++.h>
using namespace std;

const int N = 240001;
const int K = 490;

int n,m,q;
int sh[N],cu[N];
vector<int> shc[N],cus[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++)
    { 
        int am; cin >> am;
        for(int j = 0;j < am;j++){ int x; cin >> x; shc[i].push_back(x); if(am>K) cus[x].push_back(i);  }
    }
    while(q--)
    {
        int t,x,y;
        cin >> t;
        if(t==1)
        {
            cin >> x >> y;
            int c = y-sh[x];
            sh[x] = y;
            if(shc[x].size()<=K) for(int i : shc[x]) cu[i]+=c;
        }
        else
        {
            cin >> x;
            int ans = cu[x];
            for(int y : cus[x]) ans+=sh[y];
            cout << ans << '\n';
        }
    }
}
