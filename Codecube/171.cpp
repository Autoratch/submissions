#include <bits/stdc++.h>
using namespace std;

const int N = 4e5;
const int MAXN = 1 << 19;

int a[MAXN],s[MAXN << 1],q;
string st;

void build(int l,int r,int idx)
{
	if(l==r){ s[idx] = a[l]; return; }
	int m = (l+r)/2;
	build(l,m,idx*2);
	build(m+1,r,idx*2+1);
	s[idx] = min(s[idx*2],s[idx*2+1]);
}

int query(int l,int r,int idx,int x,int y)
{
	if(x>r or y<l) return INT_MAX;
	if(x<=l and y>=r) return s[idx];
	int m = (l+r)/2;
	return min(query(l,m,idx*2,x,y),query(m+1,r,idx*2+1,x,y));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> st;

	for(int i = 1;i <= st.length();i++)
	{
		if(st[i-1]=='(') a[i] = a[i-1]+1;
		else a[i] = a[i-1]-1;
	}
	for(int i = 1;i <= st.length();i++)
	{
		if(st[i-1]=='(') a[i+st.length()] = a[i+st.length()-1]+1;
		else a[i+st.length()] = a[i+st.length()-1]-1;
	}


	build(1,N,1);

	cin >> q;

	while(q--)
	{
		int l,r;
		cin >> l >> r;
		if(r<l) r = r+st.length();
		if(a[r]-a[l-1]!=0){ cout << "no\n"; continue; }
		if(query(1,N,1,l,r)<a[l-1]){ cout << "no\n"; continue; }
		cout << "yes\n";
	}
}
