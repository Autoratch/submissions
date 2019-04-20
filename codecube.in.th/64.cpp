#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n,ck = 0,sl,lc,all = 0;

	cin >> n;

	vector<long long> a(n),b(n);

	for(long long i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		for(long long j = 0;j < s.length();j++) if(s[j]=='/'){ sl= j; break; }
		a[i] = 0; b[i] = 0;
		long long m = 1;
		for(long long j = sl-1;j >= 0;j--)
		{
			a[i]+=m*(s[j]-'0');
			m*=10;
		}
		m = 1;
		for(long long j = s.length()-1;j > sl;j--)
		{
			b[i]+=m*(s[j]-'0');
			m*=10;
		}
		ck+=(a[i]/b[i]);
		a[i]%=b[i];
		if(a[i]==0) continue;
		long long g = __gcd(a[i],b[i]);
		a[i]/=g; b[i]/=g;
		if(i==0) lc = b[i];
		else lc = (lc*b[i])/__gcd(lc,b[i]);
	}

	for(long long i = 0;i < n;i++){ if(!a[i]) continue; a[i] = a[i]*lc/b[i]; all+=a[i]; }

	ck+=(all/lc);
	all%=lc;

	long long gc = __gcd(all,lc);

	all/=gc;
	lc/=gc;
	if(all) ck++;

	cout << ck << '\n';
	if(!all) cout << '0';
	else cout << lc-all << '/' << lc;
}
