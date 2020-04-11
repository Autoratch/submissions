#include <bits/stdc++.h>
using namespace std;

int t,m,n;
vector<vector<int> > s;
vector<vector<bool> > out;
vector<vector<pair<int,int> > > up,lo,le,ri;
queue<pair<int,int> > q,tq;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> t;
    for(int c = 1;c <= t;c++)
    {
        cin >> m >> n;
        s.resize(m+1),out.resize(m+1);
        up.resize(m+1),lo.resize(m+1),le.resize(m+1),ri.resize(m+1);
        int ans = 0,each = 0;
        for(int i = 1;i <= m;i++) 
        {
            s[i].resize(n+1),out[i].resize(n+1);
            up[i].resize(n+1),lo[i].resize(n+1),le[i].resize(n+1),ri[i].resize(n+1);
            for(int j = 1;j <= n;j++) cin >> s[i][j],each+=s[i][j],out[i][j] = false;
        }
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
        {
            if(i>1) up[i][j] = {i-1,j};
            else up[i][j] = {0,0};
            if(i<m) lo[i][j] = {i+1,j};
            else lo[i][j] = {0,0};
            if(j>1) le[i][j] = {i,j-1};
            else le[i][j] = {0,0};
            if(j<n) ri[i][j] = {i,j+1};
            else ri[i][j] = {0,0};
            int am = 0,av = 0;
            for(int x = -1;x <= 1;x++) for(int y = -1;y <= 1;y++) 
            {
                if(x==0 and y==0) continue;
                if(x!=0 and y!=0) continue;
                int ai = x+i,aj = y+j;
                if(ai<1 or ai>m or aj<1 or aj>n) continue;
                am++,av+=s[ai][aj];
            }   
            if(am*s[i][j]<av) q.push({i,j});
        }
        while(true)
        {
            ans+=each;
            while(!q.empty()) 
            {
                int x = q.front().first,y = q.front().second;
                q.pop();
                if(out[x][y]) continue;
                int am = 0,av = 0;
                if(up[x][y].first) if(!out[up[x][y].first][up[x][y].second]) am++,av+=s[up[x][y].first][up[x][y].second];
                if(lo[x][y].first) if(!out[lo[x][y].first][lo[x][y].second]) am++,av+=s[lo[x][y].first][lo[x][y].second];
                if(le[x][y].first) if(!out[le[x][y].first][le[x][y].second]) am++,av+=s[le[x][y].first][le[x][y].second];
                if(ri[x][y].first) if(!out[ri[x][y].first][ri[x][y].second]) am++,av+=s[ri[x][y].first][ri[x][y].second];
                if(am*s[x][y]>=av) continue;
                tq.push({x,y});
            }   
            if(tq.empty()) break;
            while(!tq.empty())
            {
                int x = tq.front().first,y = tq.front().second;
                tq.pop();
                out[x][y] = true; each-=s[x][y];
                if(up[x][y].first) lo[up[x][y].first][up[x][y].second] = lo[x][y],q.push(up[x][y]);
                if(lo[x][y].first) up[lo[x][y].first][lo[x][y].second] = up[x][y],q.push(lo[x][y]);
                if(le[x][y].first) ri[le[x][y].first][le[x][y].second] = ri[x][y],q.push(le[x][y]);
                if(ri[x][y].first) le[ri[x][y].first][ri[x][y].second] = le[x][y],q.push(ri[x][y]);
            }
        }
        cout << "Case #" << c << ": " << ans << '\n';
    }

}
