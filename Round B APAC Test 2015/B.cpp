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

int n, x, y;
LD dp[100010];
LD dpT[100010];
LD solve()
{
	LL tot = 1LL * x * (x + 1) / 2;
	ZERO(dp);
	dp[1] = 1LL * n * 750;
	FOR(i,1,x)
	{
		ZERO(dpT);
		LL curr = 0;
		FORE(j,1,tot)
		{
			if(j > (curr * (curr + 1) / 2))
				curr++;
			if(dp[j] <= 250)
				continue;
			dpT[j] += (dp[j] - 250) * 1.0 / 3;
			dpT[j + curr] += (dp[j] - 250) * 1.0 / 3;
			dpT[j + curr + 1] += (dp[j] - 250) * 1.0 / 3;
		}
		memcpy(dp, dpT, sizeof(dp));
	}
	if(dp[y] > 250)
		return 250;
	return dp[y];
}
int main()
{
	int T;
	cin >> T;
	cout << setprecision(7);
	cout << fixed;
	FOR(z, 0, T)
	{
		cin >> n;
		cin >> x >> y;
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}