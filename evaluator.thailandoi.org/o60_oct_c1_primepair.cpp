#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int a,b,c,d,x,y,mx;
int res[N],pr[N];
bool prime[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b >> c >> d;

    for(int i = 2;i < N;i++) prime[i] = true;

    for(int i = 2;i < N;i++)
    {
        if(!prime[i]) continue;
        pr[i] = i;
        for(int j = 2;j*i < N;j++){ prime[i*j] = false; pr[i*j] = i; }
    }

    for(int i = 2;i < N;i++) res[i] = res[i/pr[i]]+1;
 
    for(int i = 2;i <= b;i++)
    {
        if(b/i==(a-1)/i or d/i==(c-1)/i) continue;
        if(res[i]<mx) continue;
        int tx = (b/i)*i,ty = (d/i)*i;
        if(res[i]>mx)
        {
            mx = res[i];
            x = tx;
            y = ty;
        }
        else
        {
            if(tx+ty>x+y){ x = tx; y = ty; }
            else if(tx+ty==x+y)
            {
                if(tx>x){ x = tx; y = ty; }
            }
        }
    }

    cout << x << ' ' << y;
}
