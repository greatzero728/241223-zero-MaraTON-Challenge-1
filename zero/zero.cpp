#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib> // For system()

using namespace std;

int main() {
    // Step 1: Download the zip file
    string downloadCommand = "curl -o problem-a-ton-sample-tests.zip https://codeforces.com/contest/2054/problem-materials/problem-a-ton-sample-tests.zip";
    int downloadResult = system(downloadCommand.c_str());

    if (downloadResult != 0) {
        cerr << "Error: Failed to download the zip file." << endl;
        return 1;
    }

    // Step 2: Unzip the downloaded file
    string unzipCommand = "unzip -o problem-a-ton-sample-tests.zip";
    int unzipResult = system(unzipCommand.c_str());

    if (unzipResult != 0) {
        cerr << "Error: Failed to unzip the file." << endl;
        return 1;
    }

    // Step 3: Read the 25 files into strings
    vector<string> fileContents;
    for (int i = 1; i <= 25; ++i) {
        string fileName = "1-" + (i < 10 ? "00" : "0") + to_string(i) + ".txt";
        ifstream inputFile(fileName);

        if (!inputFile) {
            cerr << "Error: Could not open file " << fileName << endl;
            return 1;
        }

        stringstream buffer;
        buffer << inputFile.rdbuf(); // Read file contents into buffer
        fileContents.push_back(buffer.str());

        inputFile.close();
    }

    // Step 4: Output the contents of the files (for demonstration)
    for (int i = 0; i < fileContents.size(); ++i) {
        cout << "Contents of file 1-" << (i + 1 < 10 ? "00" : "0") << i + 1 << ".txt:" << endl;
        cout << fileContents[i] << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}
