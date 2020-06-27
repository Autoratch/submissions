#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    sort(a+1,a+n+1),sort(b+1,b+n+1);
    for(int i = 1;i <= n;i++) if(a[i]>b[i]){ cout << "NE"; return 0; }
    cout << "DA";
}
