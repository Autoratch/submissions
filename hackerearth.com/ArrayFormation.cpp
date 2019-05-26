#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,a[N];
vector<int> qu,st;
bool pr[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 2;i < N;i++)
    {
        if(pr[i]) continue;
        for(int j = 2;j*i < N;j++) pr[i*j] = true;
    }

    for(int i = 0;i < n;i++) if(pr[a[i]]) st.push_back(a[i]); else qu.push_back(a[i]);

    reverse(st.begin(),st.end());

    for(int x : qu) cout << x << ' ';
    cout << '\n';
    for(int x : st) cout << x << ' ';
}
