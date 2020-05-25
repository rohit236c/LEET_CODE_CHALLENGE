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
void printV(VVI v) {
	for(VI n: v) {
		for(int i: n) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int maxUncrossedLines(vector<int>& A, vector<int>& B) {
	int n = A.size();
	int m = B.size();

	VVI dp(n+1,VI(m+1, 0));
	int mx = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int ans = 0;
			if(i == 0 || j == 0) {
				if(A[i] == B[j]) {
					dp[i][j] = 1;
				} else {
					dp[i][j]  = (i > 0 )?dp[i-1][j]:0;
					dp[i][j]  = max(dp[i][j], (j > 0)?dp[i][j-1]:0);
				}
			} else {
				if(A[i] == B[j]) {
					ans = dp[i-1][j-1] + 1;
				} else {
					ans = max(ans,max(dp[i-1][j], dp[i][j-1]));
				} 
				
				dp[i][j] = ans;
			}
			
			mx = max(mx, dp[i][j]);
		}
	}
	return mx;
}

void solve() {
	VI A{3,2}, B{2,2,2,3};
	cout << maxUncrossedLines(A,B) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}