#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n;
bool pr[N];
int fac[N];
vector<int> res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 2;i <= n;i++) pr[i] = true;
    for(int i = 2;i <= n;i++)
    {
        if(!pr[i]) continue;
        fac[i] = i;
        for(int j = 2;j*i <= n;j++) if(pr[i*j]) pr[i*j] = false,fac[i*j] = i;
    }
    for(int i = 2;i <= n;i++) res[i/fac[i]].push_back(i);
    for(int i = 1;i <= n;i++) for(int x : res[i]) cout << i << ' ';
}
