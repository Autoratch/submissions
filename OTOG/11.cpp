#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a,b;
	
	cin >> a >> b;
	
	if(a<b) swap(a,b);
	
	a--; b--;
	
	int ans = 0;
	
	for(int i = 0;i < b;i++)
	{
		int l = (a*i/b),r = (a*(i+1)/b);
		if((a*(i+1))%b!=0) r++;
		ans+=(r-l+1)-1;
	}
	
	cout << ans;
}