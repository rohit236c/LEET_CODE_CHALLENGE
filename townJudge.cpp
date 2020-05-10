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
typedef vector<bool> VB;
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
VB visited;
VVI adj;
void dfs(int v) {

	for (int u : adj[v]) {
		cout << u << " ";
		if (!visited[u]) {
			visited[u] = true;
			dfs(u);
		}
	}
}
int findJudge(int N, vector<vector<int>>& trust) {
	adj.assign(N, VI());
	visited.assign(N, false);
	for (VI edges : trust) {
		int u = edges[0], v = edges[1];
		u--, v--;
		adj[v].PB(u);
	}
	dfs(0);
	for (int i = 0; i < N; i++) {
		cout << visited [i] << " ";
		if (!visited[i] && adj[i].size() == N - 1) {
			return i + 1;
		}
	}
	return -1;
}
int findJudgeII(int N, VVI trust) {
	vector<pair<int, int>>ans(N + 1);
	for (int i = 0; i < trust.size(); i++)
	{
		ans[trust[i][0]].first++;
		ans[trust[i][1]].second++;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (ans[i].first == 0 && ans[i].second == N - 1)
			return i;
	}
	return -1;
}
void solve() {
	int N = 2;
	VVI trust = {{2, 1}, {1, 2}};

	cout << findJudge(N, trust);



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}