#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n;
vector<int> a[N];
bool used[N];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            used[i] = 0;
            a[i].clear();
            int x;
            cin >> x;
            while(x--){ int y; cin >> y; a[i].push_back(y); }
        }
        for(int i = 1;i <= n;i++)
        {
            int each = -1;
            for(int x : a[i]) if(!used[x]){ used[x] = true; each = x; break; }
            ans[i] = each;
        }
        bool bet = false;
        for(int i = 1;i <= n;i++) if(ans[i]==-1)
        {
            bet = true;
            for(int j = 1;j <= n;j++) if(!used[j])
            {
                cout << "IMPROVE\n" << i << ' ' << j << '\n';
                break;
            }
            break;
        }
        if(!bet) cout << "OPTIMAL\n";
    }
}
