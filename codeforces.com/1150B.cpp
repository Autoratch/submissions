#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int n;
char a[N][N];
bool visited[N][N];

bool solve(int x,int y)
{
    for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
    {
        if(i!=0 and j!=0) continue;
        int ai = x+i,aj = y+j;
        if(ai<0 or ai>=n or aj<0 or aj>=n) return false;
        if(a[ai][aj]=='#') return false;
        if(visited[ai][aj]) return false;
        visited[ai][aj] = true;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    {
        if(a[i][j]=='#') continue;
        if(visited[i][j]) continue;
        if(!solve(i+1,j)){ cout << "NO"; return 0; }
    }

    cout << "YES";
}
