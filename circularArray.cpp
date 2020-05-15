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
int kadane(VI nums) {
	int n = nums.size();
	int sum = nums[0], curSum = nums[0];
	for(int i = 1; i < n; i++) {
		sum = max(nums[i], nums[i] + sum);
		curSum = max(curSum,sum);
	}
	return curSum;
}
int maxSubarraySumCircular(vector<int> A) {
	int n = A.size();
	int maxA = kadane(A);

	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += A[i];
		A[i] = (-1)*A[i];
	}
	int max2 = sum + kadane(A);

	return max(maxA,max2);
}
void solve() {
	VI nums{8, -1, -3, 8, -6, -9, 2, 4};
	cout << "ans = " << maxSubarraySumCircular(nums);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}