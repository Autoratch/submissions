#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  
  cin >> n;
  
  vector<int> a(n*2);
  
  for(int i = 0;i < n*2;i++) cin >> a[i];
  
  sort(a.begin(),a.end());
  
  cout << a[n-1];
}