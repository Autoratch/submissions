#include "grader.h"
#include "memory.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> a[26];

void play()
{
    for(int i = 1;i <= 50;i++){ char x = faceup(i); a[x-'A'].push_back(i); }
    for(int i = 0;i < 25;i++) faceup(a[i][0]),faceup(a[i][1]);
}
