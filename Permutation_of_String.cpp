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
class Solution {
public:
	bool isEqual(vector<int>a, vector<int>b) {

		for (int i = 0; i < 26; i++)
			if (a[i] != b[i])
				return false;

		return true;
	}
	bool checkInclusion(string s1, string s2) {
		int m = s1.size();
		int n = s2.size();
		if (m > n) return false;
		vector<int>a(27, 0);
		vector<int>b(27, 0);
		for (int i = 0; i < m; i++) {
			a[s1[i] - 'a']++;
			b[s2[i] - 'a']++;
		}

		if (isEqual(a, b)) return true;

		for (int i = 1; i <= n - m; i++) {

			b[s2[i - 1] - 'a']--;
			b[s2[i + m - 1] - 'a']++;
			if (isEqual(a, b)) return true;
		}
		return false;
	}
};

void solve() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}