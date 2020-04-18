#include <bits/stdc++.h>
using namespace std;

int n,sum;
vector<int> a[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for(int i = 1;i <= n;i++) 
	{
		int x;
		cin >> x;
		sum+=x;
		a[x].push_back(i);
	}
	
	sum = sum*2/n;
	
	for(int i = 1;i < min(sum,101);i++)
	{
		if(i*2==sum) for(int j = 0;j < a[i].size()/2;j++) cout << a[i][j] << ' ' << a[i][j+a[i].size()/2] << '\n'; 
		else for(int j = 0;j < a[i].size();j++) cout << a[i][j] << ' ' << a[sum-i][j] << '\n';
		if(sum-i<101) a[sum-i].resize(0);
	}
}