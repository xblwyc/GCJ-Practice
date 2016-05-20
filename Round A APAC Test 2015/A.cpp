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

string LED[10] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
int led[10];
int n;
string A[110];
int a[110];
set<int> res;
void check(int statu, int start)
{
	FOR(i,0,n)
	{
		if(a[i] != (statu & led[start]))
			return;
		start--;
		if(start < 0)
			start += 10;
	}
	res.insert(statu & led[start]);
}
string solve()
{
	ZERO(a);
	FOR(i,0,n)
	{
		FOR(j,0,A[i].size())
		{
			if(A[i][j] == '1')
			a[i] += (1 << j);
		}
	}
	res.clear();
	FOR(i,0,pw(7))
	{
		FOR(j,0,10)
		{
			check(i,j);
		}
	}
	if(res.size() != 1)
		return "ERROR!";
	string ans;
	int val = *res.begin();
	FOR(i,0,7)
	{
		ans.PB(val % 2 + '0');
		val /= 2;
	}
	return ans;
}
int main()
{
	ZERO(led);
	FOR(i,0,10)
	{
		FOR(j,0,LED[i].size())
		{
			if(LED[i][j] == '1')
			led[i] += (1 << j);
		}
	}
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		FOR(i,0,n)
		cin >> A[i];

		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}