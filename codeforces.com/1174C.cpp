#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int npr[N],ans[N];
vector<int> pr;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 2;i <= n;i++) 
    {
        if(npr[i]) continue;
        pr.push_back(i);
        for(int j = 2;j*i <= n;j++) npr[i*j] = true;
    }

    int cnt = 0;

    for(int x : pr)
    {
        cnt++;
        for(int i = 1;i*x <= n;i++) if(!ans[i*x]) ans[i*x] = cnt;
    }

    for(int i = 2;i <= n;i++) cout << ans[i] << ' ';
}
