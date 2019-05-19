#include <bits/stdc++.h>
using namespace std;

const long long M = 1e5 + 1;

long long n,l,sum;
vector<long long> s;
long long a[M],x[M],mx[M];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for(long long i = 0;i < n;i++) cin >> a[i];
	for(long long i = 0;i < n;i++)
	{
		auto it = upper_bound(s.begin(),s.end(),a[i]);
		if(it==s.end()) s.push_back(a[i]),x[i] = s.size()-1;
		else *it = a[i],x[i] = it-s.begin();
	}

	l = s.size();
	mx[l] = LLONG_MAX;
	for(long long i = n-1;i >= 0;i--)
	{
		if(a[i]>mx[x[i]+1]) continue;
		mx[x[i]] = max(mx[x[i]],a[i]);
	}

	for(long long i = 0;i < l;i++) sum+=mx[i];

	cout << l << ' ' << sum;
}
