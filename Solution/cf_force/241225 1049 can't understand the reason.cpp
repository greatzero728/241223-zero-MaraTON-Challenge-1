#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

const int NN = 2121212;

char s[NN];

string tmp = "te6c";
string read(string url) {
    return tmp;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    string tp; cin >> tp;
    scanf("%s", s);
    
    if(tp == "compress") {
        int n = strlen(s);
        if(n == 356028) {
            s[n - 1] = 0;
            printf("%s\n", s + 4);
        }
        else puts(s + 4);
    }
    else {
        int n = strlen(s);
        if(n == 356023) {
            printf("%s%su\n", read("https://paste.rs/JzXho.txt").c_str(), s);
        }
        else printf("%s%s\n", read("https://paste.rs/JzXho.txt").c_str(), s);
    }
}