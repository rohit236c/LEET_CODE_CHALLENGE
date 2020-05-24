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
TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.size() == 0) return NULL;
    TreeNode*root = new TreeNode(preorder[0]);

    for (int i = 1; i < preorder.size(); i++) {
        TreeNode* cur = root;
        bool bharah = false;
        TreeNode*node = new TreeNode(preorder[i]);
        while (!bharah) {
            if (cur->val > node->val) {
                if (cur->left == NULL) {
                    cur->left = node;
                    bharah = true;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right == NULL) {
                    cur->right = node;
                    bharah = true;
                } else {
                    cur = cur->right;
                }
            }
        }
    }
    return root;
}
void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}
