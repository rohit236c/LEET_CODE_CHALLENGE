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
typedef pair<char, int>pcc;
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

string removeKdigits(string num, int k) {
	string ans;
	for(char c: num) {

		while(ans.size() && ans.back() > c && k) {
			ans.pop_back();
			k--;
		}
		if(ans.size() != 0 || c!= '0') ans.push_back(c);
	}
	while(ans.size() && k) {
		ans.pop_back();
		k--;
	}
	if(ans.size() == 0) return "0";

	return ans;

}
void solve() {
	string s = "219";
	cout << removeKdigits(s, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}

