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
VI nums;
int n = nums.size();
int ans = 0;

void printV(VS v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
// nums--price array___,2 options either to sell or buy it at first i could only buy it..
map<int, int>m;

int maxProfit(int idx) {
	if (idx == n) return 0;

	int ans = 0;

	for (int i = idx; i < n; i++) {
		int profit = 0;
		for (int j = i + 1; j < n; j++) {
			if (nums[i] < nums[j]) {
				int mp = maxProfit(j + 1) + (nums[j] - nums[i]);
				if (profit < mp) {
					profit = mp;
				}
			}
		}
		ans = max(ans, profit);
	}

	return ans;
}


void solve() {
	int size;
	cin >> size;

	nums.clear();
	nums.resize(size);
	for (int i = 0; i < size; i++) cin >> nums[i];


	n = size;


	cout << "@" << maxProfit(0) << " " ;


}
void leet_4th() {
	VI nums{4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
	int n = nums.size();

	int idx = 0, jidx = 1;
	while (jidx < nums.size() && idx < nums.size()) {
		if (nums[idx] == 0 && nums[jidx] != 0) {
			swap(nums[idx], nums[jidx]);
			idx++;
			jidx++;
		} else if (nums[idx] == 0 && nums[jidx] == 0) {
			jidx++;
		} else if (nums[idx] && nums[jidx]) {
			idx++;
			jidx++;
		} else {
			idx++;
		}
	}
	// printV(nums);
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string,VS>m;
	for(string str: strs) {
		
		string cur = str;
		sort(cur.begin(), cur.end());
		if(m.find(cur) == m.end()) {
			m[cur].PB(str);
		} else {
			m[cur].PB(str); 
		}
	}
	int idx = 0;
	int inserted = 0;
	// for(auto val: m) {
	// 	ans[idx].PB(val.second);
	// }
	std::vector<std::vector<string>> ans(m.size());

	for(auto itr: m) {
		ans[idx] = (itr.second);
		idx++;
	}
	return ans;

}
void solve_six() {
	VS data{"eat", "tea", "tan", "ate", "nat", "bat"};
	std::vector<std::vector<string>> ans = groupAnagrams(data);
	for(VS str: ans) {
		for(string s: str) {
			cout << s << " ";
		}
		cout << endl;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// solve();
	solve_six();
	return 0;
}