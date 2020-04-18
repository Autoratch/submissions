#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,k,ans;
int a[N];
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a,a+n);

    int l = 0,r = n/2;

    while(l<n and r<n)
    {
        if(visited[l]) l++;
        else if(a[r]-a[l]<k) r++;
        else ans++,visited[r] = true,l++,r++;
    }

    cout << ans;
}
