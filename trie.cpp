#include<bits/stdc++.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

class node {
public:
	char ch;
	unordered_map<char, node*>map;
	bool end;

	node(char c) {
		ch = c;
		end = false;
	}
};
class Trie {
	node*head;
public:
	Trie() {
		head = new node('1');
	}

	void insert(string word) {
		node* temp = head;

		for (char c : word) {
			if (temp->map.find(c) != temp->map.end()) {
				temp = temp->map[c];
			} else {
				node* n = new node(c);
				temp->map[c] = n;
				temp = temp->map[c];
			}
		}
		temp->end = true;
	}

	bool search(string word) {
		node*temp = head;

		for (int i = 0; i < word.size(); i++) {
			cout << temp->ch << word[i] << endl;
			if (temp->map.find(word[i]) != temp->map.end()) {
				temp = temp->map[word[i]];
			} else {
				cout << word[i] << " ";
				return false;
			}
		}

		return temp->end;
	}

	bool startsWith(string prefix) {
		node*temp = head;

		for (char c : prefix) {
			if (temp->map.find(c) != temp->map.end()) {
				temp = temp->map[c];
			} else {
				return false;
			}
		}
		return true;
	}

};



void solve() {
	Trie*t = new Trie();
	t->insert("apple");
	cout << t->search("apple") << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}