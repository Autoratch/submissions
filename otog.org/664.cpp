#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	
	while(cin >> n) a.push_back(n);
	
	reverse(a.begin(),a.end());
	
	int mx = 0,ans = 0;
	
	for(int x : a) if(x>mx) mx = x,ans++;
	
	cout << ans;
}