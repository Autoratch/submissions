#include <bits/stdc++.h>
using namespace std;

int m,n;
vector<int> a;
vector<pair<int,int> > res;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> m >> n;

	a.resize(m);
	for(int i = 0;i < m;i++) cin >> a[i];

	sort(a.begin(),a.end());

	int now = 1;
	
	if(a[0]!=1) res.push_back({1,1}),now+=a[0]-1;

	for(int i = 0;i < m;i++)
	{
		if(i==m-1 or (i!=m-1 and a[i]+1!=a[i+1])) res.push_back({now,a[i]+1});
		if(i!=m-1) now+=a[i+1]-a[i]-1;
	}

	for(int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		auto it = upper_bound(res.begin(),res.end(),make_pair(x,INT_MAX));
		it--;
		int idx = it->first,val = it->second;
		cout << x-idx+val << ' ';
	}
}
