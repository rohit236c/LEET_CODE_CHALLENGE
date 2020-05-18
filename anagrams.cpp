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
	bool isEqual(int a[], int b[]) {

		for (int i = 0; i < 26; i++)
			if (a[i] != b[i])
				return false;
		return true;
	}

	vector<int> findAnagrams(string s, string p) {

		int m = s.size();
		int l = p.size();
		if (s == "" || l > m) return {};
		vector<int>ans;
		int a[26] = {0}, b[26] = {0}, c = 0;
		for (int i = 0; i < l; i++)
		{
			a[s[i] - 'a']++;
			b[p[i] - 'a']++;
		}
		if (isEqual(a, b)) ans.push_back(0);
		for (int i = 1; i <= m - l; i++)
		{
			a[s[i - 1] - 'a']--;
			a[s[i + l - 1] - 'a']++;
			if (isEqual(a, b)) ans.push_back(i);
		}
		return ans;
	}

};


void solve() {

	// string s = "cbaebabacd";
	string s = "cbacba";
	string p = "abc";

	VI ans = findAnagrams(s, p);
	printV(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}