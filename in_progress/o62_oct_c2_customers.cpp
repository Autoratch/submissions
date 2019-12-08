#include <bits/stdc++.h>
using namespace std;

const int N = 120001;
const int K = 500;

int n,m,q;
vector<pair<int,int> > res,each[K];
int fi[N],la[N],va[K],vae[K+1][K+1],qs[K+1][K+1];
bool sm[K],no[N];
int ll[N][K],rr[N][K];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) 
    {
        int y;
        cin >> y;
        no[i] = y;
        fi[i] = INT_MAX,la[i] = INT_MIN;
        while(y--)
        {
            int x;
            cin >> x;
            res.push_back({i,x});
            fi[i] = min(fi[i],(int)res.size()-1);
            la[i] = max(la[i],(int)res.size()-1);
        }
    }
    for(int i = 0;i < K;i++) 
    {
        for(int j = i*K;j < (i+1)*K;j++) 
        {
            if(j>=res.size()) break;
            each[i].push_back({res[j].second,res[j].first});
        }
        if(each[i].size()==0) continue;
        if(each[i].front().second==each[i].back().second) sm[i] = true;
        sort(each[i].begin(),each[i].end());
    }
    for(int x = 1;x <= n;x++)
    {
        for(int i = 0;i < K;i++) 
        {
            auto lo = lower_bound(each[i].begin(),each[i].end(),make_pair(x,-1));
            auto up = upper_bound(each[i].begin(),each[i].end(),make_pair(x,INT_MAX));
            ll[x][i] = lo-each[i].begin(),rr[x][i] = up-each[i].begin(); rr[x][i]--;
        }
    }
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x,y;
            cin >> x >> y;
            if(!no[x]) continue;
            int l = fi[x],r = la[x];
            int bl = l/K,br = r/K;
            for(int i = bl+1;i < br;i++) va[i] = y;
            for(int i = bl*K;i < (bl+1)*K;i++) if(each[i/K][i%K].second==x) vae[i/K][i%K] = y;
            for(int i = bl*K;i < (bl+1)*K;i++){ qs[i/K][i%K] = vae[i/K][i%K]; if(i>bl*K) qs[i/K][i%K]+=qs[i/K][i%K-1]; }
            for(int i = br*K;i < (br+1)*K;i++) if(each[i/K][i%K].second==x) vae[i/K][i%K] = y;
            for(int i = br*K;i < (br+1)*K;i++){ qs[i/K][i%K] = vae[i/K][i%K]; if(i>br*K) qs[i/K][i%K]+=qs[i/K][i%K-1]; }
        }
        else
        {
            int x;
            cin >> x;
            int ans = 0;
            for(int i = 0;i < K;i++) 
            {
                int l = ll[x][i],r = rr[x][i];
                if(sm[i]){ if(l!=r) ans+=va[i]; }
                else
                {
                    if(r>=0) ans+=qs[i][r];
                    if(l) ans-=qs[i][l-1];
                }
            }
            cout << ans << '\n';
        }
    }
}
