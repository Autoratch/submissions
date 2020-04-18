#include <bits/stdc++.h>
using namespace std;

int t,n;
vector<int> a[12];
int ans[1001];
int p[] = {0,2,3,5,7,11,13,17,19,23,29,31};
map<int,int> mp;
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        s.clear();
        for(int i = 1;i <= 11;i++) a[i].clear();
        for(int i = 1;i <= n;i++)
        {
            int x;
            cin >> x;
            for(int j = 1;j <= 11;j++) 
            {
                if(x%p[j]==0){s.insert(j); ans[i] = j; break; }
            }
        }
        cout << s.size() << '\n';
        int id = 0;
        mp.clear();
        for(int x : s) mp[x] = ++id;
        for(int i = 1;i <= n;i++) cout << mp[ans[i]] << ' ';
        cout << '\n';
    }
}
