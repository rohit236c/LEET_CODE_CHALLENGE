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
// if x == even -- x = 2*(x/2);
// if x == odd -- x = 2*(x/2) + 1;
vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);
    if (num == 0) return dp;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= num; i++) {
        dp[i] = (i & 1) + dp[i / 2];
    }
    return dp;
}
void solve() {
    int n = 2;
    VI ans = countBits(3);
    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
