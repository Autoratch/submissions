#include <bits/stdc++.h>
using namespace std;

int n = 10,x,y,cnt;

void right(){ cout << "R"; x++; cnt++; }

void left(){ cout << "L"; x--; cnt++; }

void up(){ cout << "U"; y++; cnt++; }

void down(){ cout << "D"; y--; cnt++; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 1;i <= n+1;i++) right();
    up();
    for(int i = 1;i <= n+1;i++) right();
    down();
    for(int i = 1;i <= n+1;i++) left();
    for(int i = 1;i <= n+1;i++) right();
    for(int i = 1;i <= n+1;i++) up();
    for(int i = 1;i <= 3*n;i++)
    {
        for(int j = 1;j <= 3*n;j++) left();
        for(int j = 1;j <= 3*n;j++) right();
        down();
    }
    for(int i = 1;i <= 3*n;i++) left();
    for(int i = 1;i <= 3*n;i++) up();
    int ky = y-3*n;
    for(int i = 1;i <= 2*n+2;i++)
    {
        for(int j = 1;j <= n/2*i;j++) left();
        up();
        for(int j = 1;j <= n/2;j++)
        {
            left();
            int ey = y;
            while(y>ky) down();
            while(y!=ey) up();
        }
        for(int j = 1;j <= n/2*i+n/2;j++) right();
        down(),down();
    }
    while(y!=ky) down();
    down();
    for(int i = 1;i <= n*n*5;i++) left();
    cout << "ULLLLLLLLLDDDRDL";
    cout << "UUUURDDRDLL";
    cout << "UUURRDDDRDLUUUURDDDRDLUUUURDDRDLLL";
    cout << "UUURRRDDRDLLL";
    cout << "UUURRRRRRDLL";
    cout << "ULDDDRDLL";
    cout << "RUUUULDDRDL";
}
