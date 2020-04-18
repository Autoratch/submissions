#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int t,n,pa[N];
pair<int,int> res[N],ols[N],nes[N],oln[N],nen[N];
int s[N],ns[N];

int main()
{
    cin >> t >> n;
    while(t--)
    {
        for(int i = 1;i <= n/2;i++) pa[i] = (i-1)/5+1;
        for(int i = 1;i <= n/2;i++) 
        {
            cout << i << endl;
            cin >> res[i].first;
            cout << n+1-i << endl;
            cin >> res[i].second;
            if(res[i].first==res[i].second) s[pa[i]] = i;
            else ns[pa[i]] = i;
        }
        for(int i = 2;i <= n/10;i+=2)
        {
            ols[i] = res[s[i]],oln[i] = res[ns[i]];
            cout << s[i] << endl;
            cin >> nes[i].first;
            cout << ns[i] << endl;
            cin >> nen[i].first;
            if(i<n/10)
            {
            ols[i+1] = res[s[i+1]],oln[i+1] = res[ns[i+1]];
            cout << s[i+1] << endl;
            cin >> nes[i+1].first;
            cout << ns[i+1] << endl;
            cin >> nen[i+1].first;
            }
            ols[1] = res[s[1]],oln[1] = res[ns[1]];
            cout << s[1] << endl;
            cin >> nes[1].first;
            cout << ns[1] << endl;
            cin >> nen[1].first;
            int tr;
            cout << "1" << endl;
            cin >> tr;
            cout << "1" << endl;
            cin >> tr;
            cout << "1" << endl;
            cin >> tr;
            cout << "1" << endl;
            cin >> tr;
            for(int j = 1;j <= min(n/2,(i+1)*5);j++)
            {
                if(res[j].first==res[j].second)
                {
                    if(ols[pa[j]].first!=nes[pa[j]].first) res[j].first^=1,res[j].second^=1;
                }
                else
                {
                    if(oln[pa[j]].first!=nen[pa[j]].first) res[j].first^=1,res[j].second^=1;
                }
                pa[j] = 1;
            }
        }
        string ans = "";
        for(int i = 1;i <= n/2;i++) ans+=(char)(res[i].first+'0');
        for(int i = n/2;i >= 1;i--) ans+=(char)(res[i].second+'0');
        cout << ans << endl;
        char c;
        cin >> c;
        if(c=='N') return 0;
    }
}


