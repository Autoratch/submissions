#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> a;
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    int lst;
    cin >> lst;
    for(int i = 1;i < m;i++)
    {
        int x;
        cin >> x;
        if(x==lst) a.push_back(x-lst);
        else a.push_back(x-lst-1);
        lst = x;
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    for(int i = k-1;i < a.size();i++) ans+=a[i];

    cout << ans;
}
