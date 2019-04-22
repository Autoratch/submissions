#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
long long sum,mn,mu = 1;
bool ze;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while(n--)
    {
        char c;
        long long x;
        cin >> c >> x;
        if(c=='+') sum+=x;
        else if(c=='-') mn+=x;
        else 
        {
            if(x==0) ze = true;
            else mu*=x;
        }
    }

    sum*=mu;
    if(!ze) sum-=mn;

    cout << sum;
}
