#include<cstdio>
#include<string>

using namespace std;

//main
string binary_to_minHash(string s) {
    
}
string minHash_to_binary(string s) {
    
}

string hash_to_binary(string s) {
    
}
string binary_to_hash(string s) {
    
}

string compress(string s) {
    return binary_to_minHash(hash_to_binary(s));
}

string decompress(string s) {
    return binary_to_hash(minHash_to_binary(s));
}

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
    
    if(flag) printf("%s\n", compress(string(s)).c_str());
    else printf("%s\n", decompress(string(s)).c_str());
}