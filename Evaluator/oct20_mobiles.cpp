#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 10) + 1;

int n;
int a[N][N];

void update(int x,int y,int val)
{
    for(int i = x;i < N;i+=(i & -i)) for(int j = y;j < N;j+=(j & -j)) a[i][j]+=val;
}

int read(int x,int y)
{
    int val = 0;
    for(int i = x;i > 0;i-=(i & -i)) for(int j = y;j > 0;j-=(j & -j)) val+=a[i][j];
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true)
    {
        int t;
        cin >> t;
        if(t==3) return 0;
        if(t==0) cin >> n;
        else if(t==1)
        {
            int x,y,k;
            cin >> x >> y >> k;
            x++; y++;
            update(x,y,k);
        }
        else
        {
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1++; y1++; x2++; y2++;
            cout << read(x2,y2)-read(x2,y1-1)-read(x1-1,y2)+read(x1-1,y1-1) << '\n';
        }
    }
}
