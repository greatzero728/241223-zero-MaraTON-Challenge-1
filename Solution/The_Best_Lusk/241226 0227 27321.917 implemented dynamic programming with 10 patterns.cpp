#include<cstdio>
#include<string>
#include<bitset>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define y second
#define x first

using namespace std;
using pci = pair<char, int>;
using psi = pair<string, int>;

const int NN = 10, inf = 1e9;

vector<string> patterns = {"0","1","00","10","01","11","100","001","010","011","110","101","1000","0001","0100","0010","0011","1100","0110","1010","0101","1001","1011","00011","11000","00110","10100","00101","01100","01010","10001","10010","01001","11100","00111","01110","11010","01011","01101","11001","10110","10011","000011","110000","101000","000101","000110","011000","010001","001010","001001","000111","010010","001011"};
int len[NN];
string matching = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

map<char, string> c_s;

string d_dynamic_using_pattern_based_10(string s) {
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(NN, inf));
    
    for(int i = 0; i < NN; i++) {
        if(patterns[i] == s.substr(0, len[i])) dp[len[i] - 1][i] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < NN; j++) if(dp[i][j] < inf) {
            for(int J = 0; J < NN; J++) if(i + len[J] < n && patterns[J] == s.substr(i + 1, len[J])) {
                int I = i + len[J], mn = dp[i][j] + 1;
                if(j == J) mn--;
                if(dp[I][J] > mn) dp[I][J] = mn;
            }
        }
    }
    
    string ans;
    for(int i = n - 1; i >= 0; ) {
        int mn = *min_element(dp[i].begin(), dp[i].end());
        for(int j = 0; j < NN; j++) if(mn == dp[i][j]) {
            ans += matching[j]; i -= len[j];
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() & 3) ans += '=';
    
    return ans;
}
string u_dynamic_using_pattern_based_10(string s) {
    string ans;
    for(char c : s) ans += c_s[c];
    return ans;
}

string binary_to_minHash(string s) {
    return d_dynamic_using_pattern_based_10(s);
}
string minHash_to_binary(string s) {
    return u_dynamic_using_pattern_based_10(s);
}

// Convert TON block hash to binary using 6-bit representation
string hash_to_binary(string s) {
    string ans;
    for (char c : s) {
        int value;
        if (c >= 'A' && c <= 'Z') {
            value = c - 'A';
        } else if (c >= 'a' && c <= 'z') {
            value = c - 'a' + 26;
        } else if (c >= '0' && c <= '9') {
            value = c - '0' + 52;
        } else if (c == '+') {
            value = 62;
        } else if (c == '/') {
            value = 63;
        } else break;
        ans += bitset<6>(value).to_string();
    }
    return ans;
}

// Convert binary to TON block hash using 6-bit representation
string binary_to_hash(string s) {
    string ans;
    for (size_t i = 0; i < s.size(); i += 6) {
        if (i + 6 > s.size()) {
            // Add padding if the remaining bits are less than 6
            s.append(6 - (s.size() - i), '0');
        }
        int value = bitset<6>(s.substr(i, 6)).to_ulong();
        if (value < 26) {
            ans += 'A' + value;
        } else if (value < 52) {
            ans += 'a' + (value - 26);
        } else if (value < 62) {
            ans += '0' + (value - 52);
        } else if (value == 62) {
            ans += '+';
        } else if (value == 63) {
            ans += '/';
        }
    }
    // Add padding characters to make the output length a multiple of 4
    while (ans.size() % 4 != 0) {
        ans += '=';
    }
    return ans;
}


string compress(string s) {
    return binary_to_minHash(hash_to_binary(s));
}

string decompress(string s) {
    return binary_to_hash(minHash_to_binary(s));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    for(int i = 0; i < NN; i++) {
        len[i] = patterns[i].size();
        c_s[matching[i]] = patterns[i];
    }
    
    string mode, s;
    cin>>mode>>s;
    
    if(mode[0] == 'c') printf("%s\n", compress(string(s)).c_str());
    else printf("%s\n", decompress(string(s)).c_str());
}
