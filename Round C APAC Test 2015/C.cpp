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

int x;
int f[15];
int dp[1001000];
vector<int> fac;
int rec(int xx)
{
	if(dp[xx] != -1)
		return dp[xx];
	int res = 0;
	int xxx = xx;
	while(xxx)
	{
		if(f[xxx % 10] == 0)
		{
			res = INF;
			break;
		}
		xxx /= 10;
		res++;
	}
	for(int i = 2; i * i <= xx; i++)
	{
		if(xx % i == 0)
			res = min(res, rec(i) + rec(xx / i) + 1);
	}
	return dp[xx] = res;
}
int solve()
{
	fac.clear();
	NEG(dp);
	int xx = x;
	for(int i = 2; i * i <= xx; i++)
	{
		if(xx % i == 0)
		{
			fac.PB(i);
			while(xx % i == 0)
				xx /= i;
		}
	}
	return rec(x) + 1;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		FOR(i,0,10)
			cin >> f[i];
		cin >> x;
		cout << "Case #" << z + 1 << ": ";
		int res = solve();
		if(res >= INF)
			cout << "Impossible" << endl;
		else
			cout << res << endl;
	}
}