#include <bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using pcs = pair<char, string>;
vector<pcs> vec;

struct HuffmanCode {
	HuffmanCode() {}
	~HuffmanCode() {delete top;}
	
	struct node {
		node(char chr, int cnt) : chr(chr), cnt(cnt), ls(NULL), rs(NULL) {}
		~node() {delete ls, rs;}
		char chr; int cnt;
		node *ls, *rs;
	} *top;
	struct cmp {
		bool operator() (node *l, node *r) {
			return l->cnt > r->cnt;
		}
	};
	
	void print(node *root, string str) {
		if(root == NULL) return;
		if(root->chr == '$') {
			print(root->ls, str + "0");
			print(root->rs, str + "1");
		}
		if(root->chr != '$') {
            vec.push_back({root->chr, str});
			print(root->ls, str + "0");
			print(root->rs, str + "1");
		}
	}
	
	void build(vector<char> &chr, vector<int> &cnt, int size) {
		node *ls, *rs;
		priority_queue<node*, vector<node*>, cmp> pq;
		
		for(int i = 0; i < size; i++) {
			pq.push(new node(chr[i], cnt[i]));
		}
		
		while(pq.size() != 1) {
			ls = pq.top(), pq.pop();
			rs = pq.top(), pq.pop();
			
			top = new node('$', ls->cnt + rs->cnt);
			top->ls = ls, top->rs = rs, pq.push(top);
		}
		print(pq.top(), "");
	}
} hc;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    vector<char> chr; vector<int> cnt;
    for(int i = 0; i < 65; i++) {
        char c; scanf(" %c", &c);
        chr.push_back(c);
        int x; scanf("%d", &x);
        cnt.push_back(x);
    }
    hc.build(chr, cnt, 65);
    
    for(pcs p : vec) cout<<"c_s['"<<p.x<<"']=\""<<p.y<<"\","; puts("");
    
    map<char, string> c_s;
    map<string, char> s_c;
    c_s['Z']="000000",c_s['6']="000001",c_s['q']="000010",c_s['u']="000011",c_s['T']="000100",c_s['X']="000101",c_s['V']="000110",c_s['W']="000111",c_s['A']="001",c_s['C']="01000",c_s['a']="010010",c_s['P']="010011",c_s['O']="010100",c_s['J']="010101",c_s['N']="010110",c_s['y']="010111",c_s['R']="011000",c_s['H']="011001",c_s['I']="01101",c_s['k']="011100",c_s['L']="011101",c_s['g']="01111",c_s['s']="100000",c_s['8']="100001",c_s['c']="100010",c_s['0']="100011",c_s['U']="100100",c_s['4']="100101",c_s['B']="10011",c_s['h']="101000",c_s['G']="101001",c_s['S']="101010",c_s['K']="101011",c_s['F']="101100",c_s['Y']="101101",c_s['i']="101110",c_s['M']="101111",c_s['o']="110000",c_s['w']="110001",c_s['D']="110010",c_s['=']="11001100",c_s['3']="11001101",c_s['9']="1100111",c_s['5']="1101000",c_s['+']="1101001",c_s['7']="1101010",c_s['f']="1101011",c_s['t']="1101100",c_s['2']="1101101",c_s['/']="1101110",c_s['r']="1101111",c_s['E']="111000",c_s['v']="1110010",c_s['l']="1110011",c_s['p']="1110100",c_s['1']="1110101",c_s['Q']="111011",c_s['n']="1111000",c_s['e']="1111001",c_s['m']="1111010",c_s['b']="1111011",c_s['j']="1111100",c_s['z']="1111101",c_s['d']="1111110",c_s['x']="1111111";
    for(auto p : c_s) s_c[p.y] = p.x;
    return 0;
}