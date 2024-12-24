#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<utility>
#include<algorithm>

using namespace std;

const int NN = 2121212;

char s[NN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    scanf("%s", s);
    bool flag = s[0] == 'c';
    
    scanf("%s", s);
    if(flag) puts(s + 4);
    else printf("te6c%s\n", s);
}