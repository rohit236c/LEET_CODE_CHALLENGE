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
typedef std::vector<std::vector<char>> vvc;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<bool>> vvb;
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
void printV(VI v) {
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
	map<string, VS>m;
	for (string str : strs) {

		string cur = str;
		sort(cur.begin(), cur.end());
		if (m.find(cur) == m.end()) {
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

	for (auto itr : m) {
		ans[idx] = (itr.second);
		idx++;
	}
	return ans;

}
void solve_six() {
	VS data{"eat", "tea", "tan", "ate", "nat", "bat"};
	std::vector<std::vector<string>> ans = groupAnagrams(data);
	for (VS str : ans) {
		for (string s : str) {
			cout << s << " ";
		}
		cout << endl;
	}
}
int countElements(vector<int>& arr) {
	if (arr.size() == 1) return 0;

	VI count(1100, 0);

	for (int num : arr) {
		count[num]++;
	}
	int ans = 0;
	for (int num : arr) {
		int c = count[num + 1];
		if (c > 0) ans++;

	}

	return ans;
}
void solve_seven() {
	VI nums{1, 1};

	cout << countElements(nums);
}
bool backspaceCompare(string S, string T) {
	string x  = "", y = "";
	int idx = 0, jidx = 0;
	while (idx < S.size()) {
		if (S[idx] == '#') {
			if (x.size() > 0) {
				x.pop_back();
			}
		} else {
			x.push_back(S[idx]);
		}
		idx++;
	}
	while (jidx < T.size()) {
		if (T[jidx] == '#') {
			if (y.size() > 0) {
				y.pop_back();
			}
		} else {
			y.push_back(T[jidx]);
		}
		jidx++;
	}
	return (x.compare(y) == 0) ? true : false;
}

void solve_ninth() {
	string S = "ab#c";
	string T = "ad#c";
	cout << backspaceCompare(S, T);
}
string stringShift(string s, vector<vector<int>>& shift) {
	string ans = "";
	int c1 = 0;
	int c2 = 0;
	int final = 0;
	for (VI n : shift) {
		if (n[0] == 0) {
			c1 += n[1];
		} else {
			c2 += n[1];
		}
	}
	list<char>q;
	for (char c : s) {
		q.push_back(c);
	}
	if (c1 == c2) return s;
	if (c1 > c2) {
		final = c1 - c2;
		for (int i = 1; i <= final; i++) {
			char c = q.front();
			q.pop_front();
			q.push_back(c);
		}
		for (char a : q) {
			ans = ans + a;
		}
	} else {
		final = c2 - c1;
		for (int i = 1; i <= final; i++) {
			char c = q.back();
			q.pop_back();
			q.push_front(c);
		}
		for (char a : q) {
			ans = ans + a;
		}
	}
	return ans;
}
void solve_tenth() {
	string s = "abcdefg";
	VVI matrix{{1, 1}, {1, 1}, {0, 2}, {1, 3}};
	string ans = stringShift(s, matrix);
	cout << ans;
}

int k;
VI t(1000, 0);
void build(VI  a, int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] * t[v * 2 + 1];
	}
}
int product(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 1;
	}
	if (l == tl && r == tr) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return product(v * 2, tl, tm, l, min(r, tm)) * product(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
vector<int> productExceptSelf(vector<int>& nums) {
	vector<int>ans;
	int n = nums.size();
	VI left(n + 1, 1);
	VI right(n + 1, 1);
	for (int i = 1; i < n; i++) {
		left[i] = left[i - 1] * nums[i - 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		right[i] = right[i + 1] * nums[i + 1];
	}
	for (int i = 0; i < n; i++) {
		ans.push_back(left[i]*right[i]);
	}
	// printV(left);
	// printV(right);

	return ans;
}
void solve_elev() {
	VI a{0, 0};
	VI m = productExceptSelf(a);
	printV(m);
}
bool checkValidString(string s) {
	stack<pair<char, int>>st;
	stack<pair<char, int>>extra;
	int idx = 0;
	for (char c : s) {
		pair<char, int> p{c, idx};
		if (c == '*') {
			pair<char, int> p{c, idx};
			extra.push(p);
		} else if (c == '(') {
			st.push(p);
		} else {
			if (st.empty()) {
				if (extra.empty()) return false;
				char ch  = extra.top().first;
				extra.pop();
			} else {
				char ch = st.top().first;
				st.pop();
				if (ch != '(') return false;
			}
		}
		idx++;
	}
	while (!st.empty() && !extra.empty()) {
		pair<char, int> p = extra.top();
		extra.pop();
		pair<char, int> k = st.top();
		st.pop();
		if (p.second < k.second) return false;

	}

	return st.empty();
}

void dfs(int idx, int jidx ,vvc adj, vvb& visited) {

	if(idx >= adj.size() || jidx >= adj[0].size()) return;
	if(idx < 0 || jidx < 0) return;
	if(adj[idx][jidx] == 0) return;
	if(visited[idx][jidx]) return;

	visited[idx][jidx] = true;

	if(idx < adj.size() - 1) {
		dfs(idx+1,jidx,adj,visited);
	} 
	if(jidx < adj[0].size() - 1) {
		dfs(idx,jidx+1,adj,visited);
	}
	if(idx > 0) {
		dfs(idx-1,jidx,adj, visited);
	}
	if(jidx > 0) {
		dfs(idx,jidx+1,adj, visited);
	}
	return;
	
}
int numIslands(vector<vector<char>>& grid) {
	int cnt = 0;
	int r = grid.size();
	if(r == 0) return 0;
	int c = grid[0].size();
	vector<vector<bool>> visited(r, std::vector<bool>(c,false));

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(!visited[i][j]) {
				cnt++;
				dfs(i,j,grid,visited);
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// solve();
	// solve_six();
	// solve_seven();
	// solve_ninth();
	// solve_tenth();
	// solve_elev();
	// cout << checkValidString();
	return 0;
}