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
class StockSpanner {
	stack<int>st;
	vector<int>v;
	int size;
public:
	StockSpanner() {
		ios::sync_with_stdio(false);
		cin.tie(0);
		v.push_back(-1);
		size = 0;
	}

	int next(int price) {
		int ans = 1;
		size++;
		if (v[size] > price || size == 0) {
			v.push_back(price);

			st.push(size);
			return 1;
		} else {
			int cur = size;
			while (!st.empty() && v[st.top()] <= price) {
				st.pop();
			}
			if (st.empty()) {
				ans = cur;
			}
			else {
				ans = cur - st.top();
			}
			st.push(cur);
			v.push_back(price);
		}
		return ans;
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