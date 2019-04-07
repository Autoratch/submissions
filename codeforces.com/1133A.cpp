#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a,b;

    cin >> a >> b;

    int ah,am,bh,bm;

    ah = (a[0]-'0')*10+a[1]-'0';
    bh = (b[0]-'0')*10+b[1]-'0';
    am = (a[3]-'0')*10+a[4]-'0';
    bm = (b[3]-'0')*10+b[4]-'0';

    ah = ah*60+am;
    bh = bh*60+bm;

    ah = ah+bh;
    ah/=2;

    am = ah%60;
    ah/=60;
    if(ah<10) cout << '0';
    cout << ah;
    cout << ":";
    if(am<10) cout << '0';
    cout << am;

}
