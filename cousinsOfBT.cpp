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
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

VI parents;
int d, d2;
int x, y;
int dfs(TreeNode* root, TreeNode* parent, int depth) {
	if (root == NULL) return 0;
	
	parents[root->val] = parent->val;

	if (x == root->val) {
		d = depth;
	}
	if (y == root->val) {
		d2 = depth;
	}
	dfs(root->left, root, depth + 1);
	dfs(root->right, root, depth + 1);
}
bool isCousins(TreeNode* root, int x, int y) {
	TreeNode* p = new TreeNode(-1);
	dfs(root, p, 0);

	if (parents[x] == parents[y]) return false;
	if (d == d2) return true;

	return false;

}
void solve() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}