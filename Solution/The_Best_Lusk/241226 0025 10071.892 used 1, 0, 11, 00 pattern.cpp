#include<cstdio>
#include<string>
#include<bitset>
#include<iostream>

#define y second
#define x first

using namespace std;
using pci = pair<char, int>;

//1: +, 0: /
//11: a, 00: b
string d_merge_same_components_based_10(string s) {
    int n = s.size();
    string ans;
    for(int i = 0, j = 0; i < n; i = j) {
        for(; j < n && s[i] == s[j]; j++);
        if(s[i] == '1') ans.push_back('+');
        else ans.push_back('/');
        if(j - i == 2) {
            if(s[i] == '1') ans.back() = 'a';
            else ans.back() = 'b';
        }
        else if(j - i > 1) ans += to_string(j - i);
    }
    while(ans.size() & 3) ans += '#';
    return ans;
}
string u_merge_same_components_based_10(string s) {
    int n = s.size();
    string ans;
    for(int i = 0, j; i < n && s[i] != '#'; ) if(!isdigit(s[i])) {
        int cnt = 0;
        for(j = i + 1; j < n && isdigit(s[j]); j++) {
            cnt = cnt * 10 + s[j] - '0';
        }
        if(s[i] == 'a') ans += "11";
        else if(s[i] == 'b') ans += "00";
        else {
            char c = (s[i] == '+') ? '1' : '0';
            if(cnt) while(cnt--) ans += c;
            else ans += c;
        }
        i = j;
    }
    return ans;
}

string binary_to_minHash(string s) {
    return d_merge_same_components_based_10(s);
}
string minHash_to_binary(string s) {
    return u_merge_same_components_based_10(s);
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
    
    string mode, s;
    cin>>mode>>s;
    
//    if(s.size() != 18128) return puts(s.c_str()), 0;
    
    if(mode[0] == 'c') printf("%s\n", compress(string(s)).c_str());
    else printf("%s\n", decompress(string(s)).c_str());
}
