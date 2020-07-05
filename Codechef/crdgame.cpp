#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int t,n;
int a[N],b[N];

int get(int x)
{
    int ret = 0;
    while(x) ret+=x%10,x/=10;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        int x = 0,y = 0;
        for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
        for(int i = 1;i <= n;i++) x+=(int)(get(a[i])>=get(b[i])),y+=(int)(get(b[i])>=get(a[i]));
        if(x>y) cout << "0 ";
        else if(y>x) cout << "1 ";
        else cout << "2 ";
        cout << max(x,y) << '\n';
    }
}
