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

int n,k;
int a[110];
int dp[110][110];
bool rec(int s, int e)
{
	if(s > e)
		return 1;
	if(dp[s][e] != -1)
		return dp[s][e];
	if(e - s == 2)
		return dp[s][e] = (a[e] - a[e - 1] == k && a[e - 1] - a[s] == k);
	dp[s][e] = 0;
	for(int i = s; i <= e; i++)
	{
		for(int j = s + 1; j <= e; j++)
		{
			for(int q = j + 1; q <= e; q++)
			{
				if(a[q] - a[j] == k && a[j] - a[i] == k)
					dp[s][e] |= rec(s, i - 1) & rec(i + 1, j - 1) & rec(j + 1, q - 1) & rec(q + 1, e);
			}
		}
	}
	return dp[s][e];
}
int dpp[110];
int check(int index)
{
	if(index == n)
		return 0;
	if(dpp[index] != -1)
		return dpp[index];
	int res = 1 + check(index + 1);
	FOR(i, index, n)
	{
		if(dp[index][i])
			res = min(res, check(i + 1));
	}
	return dpp[index] = res;
}
int solve()
{
	NEG(dp);
	FOR(i,0,n)
	{
		FOR(j,i,n)
		{
			dp[i][j] = rec(i,j);
		}
	}
	NEG(dpp);
	return check(0);
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		debug(z);
		cin >> n >> k;
		FOR(i,0,n)
		cin >> a[i];
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}