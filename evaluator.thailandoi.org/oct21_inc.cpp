#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int n,mxx,lst;
int a[N],pr[N],mx[N];
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        for(int j = 0;j < i;j++) if(mx[j]+1>mx[i] and a[i]>a[j]){ mx[i] = mx[j]+1; pr[i] = j; }
    }

    for(int i = 1;i <= n;i++) if(mx[i]>mxx){ mxx = mx[i]; lst = i; }

    while(lst){ ans.push_back(lst); lst = pr[lst]; }

    cout << ans.size() << '\n';
    for(int i = ans.size()-1;i >= 0;i--) cout << a[ans[i]] << '\n';
}
