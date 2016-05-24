#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ostream>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
#include <fstream>
#include <memory>
#include <sstream>
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define LD double
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define PII pair<LL, LL>
#define INF 0x3f3f3f3f
#define FUL(x) memset(x, 0x3f, sizeof(x));
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}
int n;
int dp[1010][1010];
int b[1010][1010];
int dirx[4] = {0,-1,0,1};
int diry[4] = {1,0,-1,0};
int rec(int x ,int y)
{
	if(dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 1;
	FOR(i,0,4)
	{
		int nx = x + dirx[i];
		int ny = y + diry[i];
		if(nx < 0 || nx >= n)
			continue;
		if(ny < 0 || ny >= n)
			continue;
		if(b[x][y] + 1 == b[nx][ny])
		dp[x][y] = max(dp[x][y], rec(nx, ny) + 1);
	}
	return dp[x][y];
}
void solve()
{
	NEG(dp);
	pair<int,int> res = MP(0, 0);
	FOR(i,0,n)
	FOR(j,0,n)
	{
		debug(b[i][j], rec(i,j));
		res = max(res, MP(rec(i,j), n * n - b[i][j]));
	}
	cout << n * n - res.second << " " << res.first << endl;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		FOR(i,0,n)
		FOR(j,0,n)
		cin >> b[i][j];
		cout << "Case #" << z + 1 << ": ";
		solve();
	}
}