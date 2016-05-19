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

vector<LL> pos;
LL k;
int rec(LL kk)
{
	int start = 0;
	while(start < pos.size() && pos[start] <= kk)
		start++;
	start--;
	if(pos[start] == kk)
		return 0;
	LL mid = pos[start];
	LL target = mid * 2 - kk;
	return rec(target) ^ 1;
}
int solve()
{
	return rec(k);
}
int main()
{
	LL start = 1;
	while(start <= 1e18)
	{
		pos.PB(start);
		start *= 2;
	}
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> k;
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}