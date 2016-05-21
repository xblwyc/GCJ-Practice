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

int b[1500][1500];
unordered_set<int> uset;
int n;
string solve()
{
	uset.clear();
	FORE(i,1,n*n)
	uset.insert(i);
	FOR(i,0,n*n)
	{
		unordered_set<int> uuset = uset;
		FOR(j,0,n * n)
		{
			if(uuset.count(b[i][j]) == 0)
				return "No";
			uuset.erase(b[i][j]);
		}
	}
	FOR(j,0,n*n)
	{
		unordered_set<int> uuset = uset;
		FOR(i,0,n * n)
		{
			if(uuset.count(b[i][j]) == 0)
				return "No";
			uuset.erase(b[i][j]);
		}
	}
	FOR(i,0,n)
	FOR(j,0,n)
	{
		unordered_set<int> uuset = uset;
		FOR(p, i * n, i * n + n)
		{
			FOR(q, i * n, i * n + n)
			{
				if(uuset.count(b[p][q]) == 0)
				return "No";
				uuset.erase(b[p][q]);
			}
		}
	}
	return "Yes";
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		FOR(i,0,n*n)
		FOR(j,0,n*n)
		cin >> b[i][j];
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}