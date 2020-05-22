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
void printV(VI v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
string frequencySort(string s) {
	std::vector<int> cnt(96, 0);
	string ans = "";

	for (char c : s) {
		cnt[c - ' ']++;
	}
	// printV(cnt);
	priority_queue<pair<int, int>>pq;
	for (int i = 0; i < 96; ++i)
	{
		pq.push({cnt[i], i});
	}
	while (!pq.empty() && pq.top().first != 0) {
		int freq = pq.top().first;
		char ch = (char)(pq.top().second + ' ');
		pq.pop();

		for (int i = 0; i < freq; i++) {
			ans += ch;
		}
	}
	return ans;

}
void solve() {
	cout << frequencySort("bbZAa");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}