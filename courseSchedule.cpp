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

VVI g;
vector<bool> visited;
vector<bool> stack;
bool dfs(int v) {
	if(!visited[v]) {
		visited[v] = true;
		stack[v] = true;
		for (int u : g[v]) {
			if (!visited[u] && dfs(u)) {
				return true;
			} else if(stack[u]) {
				return true;
			}
		}
	}
	stack[v] = false;
	return false;
	
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	int n = numCourses;
	g.assign(n, VI());
	visited.assign(n, false);
	for(int i = 0; i < prerequisites.size(); i++) {
		int u = prerequisites[i][0];
		int v = prerequisites[i][1];
		g[v].PB(u);
	}
	for(int i = 0; i < n; i++) {
		if(dfs(i)) {
			return false;
		}
	}
	return true;

}

void solve() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}