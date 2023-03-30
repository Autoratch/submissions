#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int D = 2e6 + 1;

int m,n,k,q;
bool fished[N][N];
long long ans[D],exs;
vector<pair<int,int> > cur,nex;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k >> q;
    for(int d = 1;d < D;d++)
    {
        swap(nex,cur);
        nex.clear();
        for(auto xy : cur)
        {
            int x = xy.first,y = xy.second;
            for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
            {
                if(i==0 and j==0) continue;
                if(i!=0 and j!=0) continue;
                int ai = x+i,aj = y+j;
                if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
                if(fished[ai][aj]) continue;
                fished[ai][aj] = true;
                nex.push_back({ai,aj});
            }
        }
        if(d<=k)
        {
            pair<int,int> tmp;
            cin >> tmp.first >> tmp.second;
            if(fished[tmp.first][tmp.second]) ans[d]++;
            else nex.push_back({tmp.first,tmp.second}),fished[tmp.first][tmp.second] = true;
        }
        exs+=nex.size();
        ans[d]+=ans[d-1]+exs;
    }
    while(q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}
