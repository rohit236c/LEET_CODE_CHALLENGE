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
	for (VI g : v) {
		for (int i : g) cout << i << " ";
		cout << endl;
	}
	cout << endl;
}
VI color;
bool dfs(int src, int c, VVI g) {
	if (color[src] != -1 && color[src] != c) return false;

	color[src] = c;
	bool ans = true;
	for (int v : g[src]) {

		if (color[v] == -1) {
			ans &= dfs(v, 1 - c, g);
		}

		if (color[v] != -1 && color[v] != 1 - c)
			return false;

		if (!ans) return false;
	}

	return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

	int n = dislikes.size();
	if (n == 0 || n == 1) return true;

	VVI g(N);
	color.assign(N, -1);

	for (int i = 0; i < n; i++) {
		int u = dislikes[i][0];
		int v = dislikes[i][1];
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	printV(g);
	bool ans = true;
	for (int i = 0; i < N; i++) {
		if (color[i] == -1) {
			ans &= dfs(i, 1, g);
		}
		if (!ans) return false;
	}
	return ans;

}

void solve() {
	int n = 4;
	VVI K{{1, 2}, {1, 3}, {2, 4}, {2, 3}};

	cout << "ans = " << possibleBipartition(n, K) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}