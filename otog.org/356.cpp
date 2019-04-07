#include <bits/stdc++.h>
using namespace std;

int m,n;
char a[10][10];
int mnx = INT_MAX,mny = INT_MAX,mxx,mxy;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) cin >> a[i];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(a[i][j]=='.') continue;
        int cnt = 0;
        for(int x = -1;x <= 1;x++) for(int y = -1;y <= 1;y++)
        {
            if(x==0 and y==0) continue;
            if(x!=0 and y!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<0 or ai>=m or aj<0 or aj>=n) continue;
            if(a[ai][aj]=='.') cnt++;
        }
        if(cnt>=3) continue;
        mnx = min(mnx,i); 
        mny = min(mny,j);
        mxx = max(mxx,i);
        mxy = max(mxy,j);
    }

    for(int i = mnx;i <= mxx;i++){ for(int j = mny;j <= mxy;j++) cout << a[i][j]; cout << '\n'; }
}
