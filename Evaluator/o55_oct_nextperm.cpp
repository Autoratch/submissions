#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	a.resize(n);
	
	for(int i = 0;i < n;i++) cin >> a[i];
	
	if(a[n-2]<a[n-1]){ swap(a[n-2],a[n-1]); for(int i = 0;i < n;i++) cout << a[i] << ' '; return 0; }
	
	bool t[n+1];
	
	for(int i = 1;i <= n;i++) t[i] = false;
	
	for(int i = n-1;;i--)
	{
		if(a[i]>a[i-1])
		{
			for(int j = 0;j < i-1;j++){ t[a[j]] = true; cout << a[j] << ' '; }
			for(int j = a[i-1]+1;;j++)
			{
				if(!t[j]){ t[j] = true; cout << j << ' '; for(int k = 1;k <= n;k++) if(!t[k]) cout << k << ' '; break;} 
			}
			return 0;
		}
	}
}