#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    while(n) a.push_back(n%2),n/=2;
    for(int i = a.size();i <= 6;i++) a.push_back(0);
    swap(a[0],a[4]),swap(a[2],a[3]);
    int x = 0,mul = 1;
    for(int i : a) x+=mul*i,mul*=2;
    cout << x;
}
