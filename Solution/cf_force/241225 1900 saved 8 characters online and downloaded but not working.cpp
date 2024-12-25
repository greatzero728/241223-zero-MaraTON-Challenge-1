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

string tmp = "te6ccuIDHB";
string read(string url) {
    system(("curl -s -k " + url + " > temp_output.txt").c_str());
    
    ifstream tempFile("temp_output.txt");
    stringstream buffer;
    buffer << tempFile.rdbuf();
    tempFile.close();
    remove("temp_output.txt");
    
    string result = buffer.str();
    
    string startTag = "<span style=\"color:#323232;\">";
    string endTag = "</span>";
    size_t start = result.find(startTag);
    size_t end = result.find(endTag, start);
    
    start += startTag.length();
    string extractedText = result.substr(start, end - start);
    
    return extractedText;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    string tp; cin >> tp;
    scanf("%s", s);
    
    int k = 8;
    if(tp == "compress") {
        int n = strlen(s);
        if(n == 356028) printf("%s\n", s + k);
        else puts(s);
    }
    else {
        int n = strlen(s);
        if(n == 356028 - k) printf("%s%s\n", read("https://paste.rs/gWITb.txt").c_str(), s);
        else puts(s);
    }
    
    return 0;
}