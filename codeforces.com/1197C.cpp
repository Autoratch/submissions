#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;

int n,k;
int a[N];
vector<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n-1;i++) s.push_back(a[i+1]-a[i]);

    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());

    for(int i = 0;i < k-1;i++) a[n-1]-=s[i];

    cout << a[n-1]-a[0];
}
