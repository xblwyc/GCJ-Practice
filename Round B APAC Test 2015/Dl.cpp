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

LL n, k;
LL dp[220][220];
LL check(int diff, int have)
{
	ZERO(dp);
	LL ans = 0;
	dp[diff + 1][have + 1] = 1;
	for(int i = have + 1; i < n; i++)
	{
		FOR(j,0,n + 1)
		{
			if(j == n - i)
			{
				ans += dp[j][i];
				if(ans >= k)
					return ans;
				continue;
			}
			dp[j + 1][i + 1] += dp[j][i];
			if(j != 0)
				dp[j - 1][i + 1] += dp[j][i];
		}
	}
	ans += dp[0][n];
	return ans;
}
string solve()
{
	string res;
	int curr = 0;
	FOR(i,0,n)
	{
		debug(i, check(curr, i));
		if(curr == 0 || check(curr, i) >= k)
		{
			res.PB('(');
			curr++;
		}
		else
		{
			res.PB(')');
			k -= check(curr, i);
			curr--;
		}
	}
	if(k != 1)
		return "Doesn't Exist!";
	return res;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n >> k;
		n *= 2;
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}