#include<cstdio>
#include<string>
#include<bitset>
#include<iostream>
#include<vector>
#include<cassert>

#define y second
#define x first

using namespace std;
using pci = pair<char, int>;

string convert_into_26_based(int n, char a) {
    string ans;
    while(n) ans += n % 26 + a, n /= 26;
    return ans;
}

//1: +, 0: /
// format: AaAaAaAa 
string d_merge_same_components_based_26(string s) {
    int n = s.size();
    string ans;
    if(s[0] == '1') ans.push_back('+');
    else ans.push_back('/');
    
    char c = 'a';
    for(int i = 0, j = 0; i < n; i = j) {
        for(; j < n && s[i] == s[j]; j++);
        ans += convert_into_26_based(j - i, c);
        if(c == 'a') c = 'A';
        else c = 'a';
    }
    while(ans.size() & 3) ans += '=';
    ans += "====";
    return ans;
}
string u_merge_same_components_based_26(string s) {
    while(s.back() == '=') s.pop_back();
    int n = s.size();
    string ans;
    char c = (s[0] == '+') + '0';
    
    for(int i = 1, j = 1; i < n; i = j) {
        for(; j < n && isupper(s[i]) == isupper(s[j]); j++);
        int cnt = 0;
        char a = isupper(s[i]) ? 'A' : 'a';
        for(int k = j - 1; k >= i; k--) {
            cnt = cnt * 26 + s[k] - a;
        }
        while(cnt--) ans += c;
        c = '1' - c + '0';
    }
    return ans;
}

string binary_to_minHash(string s) {
    return d_merge_same_components_based_26(s);
}
string minHash_to_binary(string s) {
    return u_merge_same_components_based_26(s);
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
    
    if(s.size() != 18128) return puts(s.c_str()), 0;
    
    if(mode[0] == 'c') printf("%s\n", compress(string(s)).c_str());
    else printf("%s\n", decompress(string(s)).c_str());
}