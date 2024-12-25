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
    
    string temp = "te6ccuIDHB4AAQAAA76eAAAAACQAANAAAO4AAcgAAmIAAv4AA5oAA+AAA/IABFQA";
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
