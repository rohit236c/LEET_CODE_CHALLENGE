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
class Node {
public:
	int d;
	Node* next;
	Node* prev;
	Node(int d) {
		this->d = d;
		next = NULL;
		prev = NULL;
	}
};
class FirstUnique {
	map<int, pair<int, Node*>>m;
	Node* head;
	Node* tail;
public:
	void addToList(Node* ptr) {
		Node* t = tail->prev;
		
		t->next = ptr;
		
		ptr->prev = t;
		ptr->next = tail;

		tail->prev = ptr;
	}
	void removeFromList(Node* ptr) {
		Node* aage = ptr->next;
		Node* peeche = ptr->prev;

		if (aage != NULL) aage->prev = peeche;
		if (peeche != NULL) peeche->next = aage;
		ptr->next = NULL;
		ptr->prev = NULL;

	}
	FirstUnique(vector<int>& nums) {
		head = new Node(-1);
		tail = new Node(-1);
		head->next = tail;
		tail->prev = head;

		// cout << tail->prev <<" "<< head << endl;
		int n = nums.size();
		int occ = 0;
		for (int i = 0; i < n; i++) {
			if (m.find(nums[i]) == m.end()) {
				cout << nums[i] <<" @ " << endl;
				Node* ptr = new Node(nums[i]);
				m[nums[i]] = {1, ptr};
				addToList(ptr);
			} else {
				removeFromList(m[nums[i]].second);
				m[nums[i]].first++;
			}
		}
	}

	int showFirstUnique() {
		return head->next->d;
	}

	void add(int value) {
		if (m.find(value) == m.end()) {
			Node* ptr = new Node(value);
			m[value] = {1, ptr};
			addToList(ptr);
		} else {
			removeFromList(m[value].second);
			m[value].first++;
		}
	}
};
void solve() {
	VI nums{1,1,1,1,1,1,1,1,61,61};
	FirstUnique f(nums);
	cout << f.showFirstUnique() << endl;
	cout << f.showFirstUnique() << endl;
	cout << f.showFirstUnique() << endl;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}
