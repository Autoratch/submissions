#include <bits/stdc++.h>
using namespace std;

int n,x,y;
stack<pair<int,int> > a;

int readInt()
{
    int x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}

int main()
{
    n = readInt();
    for(int i = 0;i < n;i++)
    {
        x = readInt(),y = readInt();
        while(!a.empty() and abs(a.top().first-x)<=y-a.top().second) a.pop();
        if(a.empty() or abs(a.top().first-x)>a.top().second-y) a.push({x,y});
    }
    printf("%d",(int)a.size());
}
