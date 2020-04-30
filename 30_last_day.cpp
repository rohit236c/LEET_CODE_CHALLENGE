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


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	vector<int> ar;
	int n;
public:
	bool isValid(TreeNode* root, int idx) {
		if (idx >= n && root != NULL) return false;

		if (root == NULL) {
			return false;
		}
		if (root == NULL && n > 1) {
			return false;
		}
		if (root != NULL && root->val != ar[idx]) return false;

		if (root->left == NULL && root->right == NULL && root->val == ar[idx] && (idx + 1 == n))  {
			return true;
		}


		bool left = isValid(root->left, idx + 1);
		bool right = isValid(root->right, idx + 1);

		return (left | right);

	}
	bool isValidSequence(TreeNode* root, vector<int>& arr) {
		ar = arr;
		n = arr.size();
		return isValid(root, 0);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}