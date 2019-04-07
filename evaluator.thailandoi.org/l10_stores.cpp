#include <bits/stdc++.h>
using namespace std;

const int N = 18;

int n;
int a[N],b[N];
double ans = double(INT_MAX);
bool t[N];
vector<int> sa,sb;

int main()
{
    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    for(int i = 0;i < (1<<n);i++)
    {
        for(int j = 0;j < n;j++) t[j] = false;
        int tmp = i,cnt = 0;
        while(tmp)
        {
            t[cnt] = tmp%2;
            tmp/=2;
            cnt++;
        }
        sa.resize(0); sb.resize(0);
        int suma = 0,sumb = 0,ca = 0,cb = 0;
        for(int j = 0;j < n;j++) if(t[j]){ ca++; suma+=a[j]; } else{ cb++; sumb+=b[j]; } 
        double ta = suma*(100.0-ca)/100.0,tb = sumb*(100.0-cb)/100.0;
        ans = min(ans,ta+tb);
    }

    cout << fixed;
    cout << setprecision(2) << ans;
}
