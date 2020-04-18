#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int t,n;
vector<int> a;

bool solve(int x)
{
	int res = 0;
	for(int i = 0;i < n;i++) res+=max(0,x-a[i]+1);
	if(res>x) return false;
	else return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		a.resize(n);
		for(int i = 0;i < n;i++) cin >> a[i];
		int l = 0,r = 100000;
		while(l<r)
		{
			int m = (l+r)/2;
			bool ok = solve(m);
			if(ok)
			{
				if(solve(m+1)) l = m+1;
				else{ l = m; break; }
			}
			else r = m-1;
		}
		cout << l+1 << endl;
	}
}