#include <bits/stdc++.h>
using namespace std;

const int N = 4;

vector<string> a(4),b;
int ans = INT_MAX;

void ch(int x,int y)
{
    for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
    {
        if(i!=0 and j!=0) continue;
        int ai = x+i,aj = y+j;
        if(ai<0 or ai>=N or aj<0 or aj>=N) continue;
        b[ai][aj] = 'w'+'b'-b[ai][aj];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 0;i < 4;i++) cin >> a[i];

    vector<int> t;
    for(int i = 0;i < (1 << 16);i++)
    {
        int tmp = i,cnt = 0,am = 0;
        t.assign(16,0);
        while(tmp) t[cnt] = tmp%2,tmp/=2,am+=t[cnt],cnt++;
        cnt = 0;
        b = a;
        for(int x = 0;x < 4;x++) for(int y = 0;y < 4;y++) if(t[cnt++]) ch(x,y);
        cnt = 0;
        char prev;
        bool ok = true;
        for(int x = 0;x < 4;x++) for(int y = 0;y < 4;y++){ if(cnt and b[x][y]!=prev) ok = false; cnt++,prev = b[x][y]; }
        if(ok) ans = min(ans,am);
    }

    if(ans==INT_MAX) cout << "Impossible";
    else cout << ans;
}
