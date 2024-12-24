#include<cstdio>
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>

using namespace std;

int main() {
    system("curl -s -k -o input.html https://paste.rs/77blM.txt");

    ifstream inputFile("input.html");

    stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();

    string html = buffer.str();

    string startTag = "<span style=\"color:#323232;\">";
    string endTag = "</span>";
    size_t start = html.find(startTag);
    size_t end = html.find(endTag, start);

    if (start != string::npos && end != string::npos) {
        start += startTag.length();
        string extractedText = html.substr(start, end - start);
        
        cerr << extractedText << endl;
    }
    
    string s;
    cin>>s>>s;
    cout<<s<<endl;
    return 0;
}
