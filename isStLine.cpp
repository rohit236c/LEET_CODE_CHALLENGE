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
int64 m, c;
bool lineOnTheLine(int x, int y) {
	long long int ans = m*(int64)x + c;

	return (y == ans);
}

bool checkStraightLine(vector<vector<int>>& coordinates) {

	int n = coordinates.size();
	int k = coordinates[0].size();

	m = ((coordinates[n - 1][1] - coordinates[0][1])) / (coordinates[n - 1][0] - coordinates[0][0]);
	c = coordinates[0][1] - (m*(coordinates[0][0]));

	for(int i = 1; i < n-1; i++) {
		if(!lineOnTheLine(coordinates[i][0],coordinates[i][1])) {
			return false;
		}
	}
	return true;
}

void solve() {
	VVI coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};

	cout << checkStraightLine(coordinates);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}