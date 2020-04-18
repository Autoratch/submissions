#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n,x;
bool out[N];
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;

    for(int i = 1;i < (1 << n);i++) if(!out[i] and i!=x) res.push_back(i),out[i^x] = true;

    cout << res.size() << '\n';
    for(int i = 0;i < res.size();i++)
    {
        int tmp = res[i];
        if(i) tmp^=res[i-1];
        cout << tmp << ' ';
    }
}
