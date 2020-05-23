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

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	int n = A.size();
	int m = B.size();

	int idx = 0, jidx = 0;
	VVI ans;
	while(idx < n && jidx < m) {
		int lo = max(A[idx][0], B[jidx][0]);
		int hi = min(A[idx][1], B[jidx][1]);

		if(lo <= hi) {
			ans.push_back(VI{lo,hi});
		}
		if(A[idx][1] < B[jidx][1]) {
			idx++;
		} else {
			jidx++;
		}
	}
	return ans;
}
void solve() {
	VVI A {{0,2},{5,10},{13,23},{24,25}}, B {{1,5},{8,12},{15,24},{25,26}};
	VVI ans = intervalIntersection(A,B);
	cout << ans.size() << endl;
	for(VI k: ans) {
		cout << k[0] << " " << k[1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}