#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,k;
int dp[N][51];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    int s = 0;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(i!=n-1) s+=x;
    }

    cout << s;
}
