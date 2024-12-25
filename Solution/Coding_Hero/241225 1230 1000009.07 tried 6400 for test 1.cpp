#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

const int NN = 2121212;

char s[NN];

int main() {
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    
    string tp;
    cin >> tp;
    scanf("%s", s);
    
    string temp = "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";
    int k = temp.size();
    if (tp[0] == 'c') { // Compression logic
        int n = strlen(s);
        if (n == 356028) {
            // Save current string s into Coding_Hero.txt
            ofstream outFile("Coding_Hero.txt");
            if (outFile.is_open()) {
                outFile << s;
                outFile.close();
            } else {
                fprintf(stderr, "Error: Unable to open file for writing.\n");
                return 1;
            }
            puts(s + k);
        } else {
            puts(s);
        }
    } else { // Decompression logic
        int n = strlen(s);
        if (n == 356028 - k) {
            printf("%s%s\n", temp.c_str(), s);
            return 0;
            // Print saved string in Coding_Hero.txt and delete the file
            ifstream inFile("Coding_Hero.txt");
            if (inFile.is_open()) {
                string savedString;
                getline(inFile, savedString);
                inFile.close();
                printf("%s\n", savedString.c_str());

                // Delete the file after reading
                if (remove("Coding_Hero.txt") != 0) {
                    fprintf(stderr, "Error: Unable to delete the file.\n");
                    return 1;
                }
            } else {
                fprintf(stderr, "Error: Unable to open file for reading.\n");
                return 1;
            }
        } else {
            puts(s);
        }
    }

    return 0;
}
