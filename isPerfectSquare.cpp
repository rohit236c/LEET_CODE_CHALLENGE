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

bool isPerfectSquare(int num) {
	for (int64 i = 1; i < (1e5); i++) {
		int64 ans = (i * i);
		if (ans == num) return true;
	}
	return false;
}
bool isPerfectSquareII(int num) {
	if (num == 1) return true;

	int low = 1, high = num / 2;

	while (low <= high) {
		double mid = (low + (high - low) / 2);

		if (mid == (num / mid)) return true;

		if (mid > num / mid) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
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