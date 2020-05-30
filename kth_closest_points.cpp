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

long long int dist(int x, int y) {
	long long int ans = ((int64)(x * x) + (int64)(y * y));

	return ans;
}
struct Compare { 
    bool operator()(PII const& p1, PII const& p2) 
    { 
        
        return p1.first > p2.first; 
    } 
};


vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	int n = points.size();
	priority_queue<PII, std::vector<PII>, Compare>pq;
	VVI ans;
	for(int i = 0; i < n; i++) {
		int u = points[i][0];
		int v = points[i][1];
		int dis = dist(u,v);
		pq.push({dis,i});
	}
	while(K  > 0 && !pq.empty()) {
		int i = pq.top().second;
		int k = pq.top().first;
		ans.push_back(points[i]);
		pq.pop();
		K--;
	}
	return ans;
}
void solve() {
	VVI points{{3,3},{5,-1},{-2,4}};
	VVI ans = kClosest(points,2);


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}