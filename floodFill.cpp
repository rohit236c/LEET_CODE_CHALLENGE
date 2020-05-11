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
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef vector<int> VI;
typedef vector<VI> VVI;
class Solution {
    VVI images;
    int color;
    vector<vector<bool>>vis;
public:
    void dfs(int sr, int sc, int er, int ec) {
        if(sr == er && sc == ec) return;
        if(sr == er || sc == ec) return;
        if(sc < 0 || sr < 0) return;
            
           
        if(vis[sr][sc]) return;
        
        int curColor = images[sr][sc];
        images[sr][sc] = color;
        vis[sr][sc] = true;
        
        if(sr + 1 < er && images[sr+1][sc] == curColor) {
            dfs(sr+1,sc,er,ec);
        }
        if(sr - 1 >= 0 && images[sr-1][sc] == curColor) {
            dfs(sr-1,sc,er,ec);
        }
        if(sc + 1 < ec && images[sr][sc+1] == curColor) {
            dfs(sr,sc+1,er,ec);
        }
        if(sc -1 >= 0 && images[sr][sc-1] == curColor) {
            dfs(sr,sc-1,er,ec);
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int er = image.size();
        if(er == 0) {
            return image;
        }
        images = image;
        color = newColor;
        int ec = image[0].size();
        vis.assign(er,vector<bool>(ec,false));
        dfs(sr,sc,er,ec);
        
        return images;
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
