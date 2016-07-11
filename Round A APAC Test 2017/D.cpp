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

LL m, n;
int k[15];
int l[15];
LL a[15][15];
LL c[15][15];
LL sum[15][15];
LL res;
void dfs(int index ,int cnt, LL att, LL money)
{
	if(cnt > 8)
		return;
	if(index >= n)
	{
		if(cnt == 8)
			res = max(res, att);
		return;
	}
	if(cnt + (n - index) < 8)
		return;
	dfs(index + 1, cnt, att, money);
	dfs(index + 1, cnt + 1, att + a[index][l[index]], money);
	for(int i = l[index]; i < k[index]; i++)
	{
		money -= c[index][i];
		if(money < 0)
			break;
		dfs(index + 1, cnt + 1, att + a[index][i + 1], money);
	}
}
LL solve()
{
	res = 0;
	dfs(0, 0, 0, m);
	return res;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> m >> n;
		FOR(i,0,n)
		{
			cin >> k[i] >> l[i];
			FOR(j,0,k[i])
			cin >> a[i][j];
			FOR(j,0,k[i] - 1)
			cin >> c[i][j];
			k[i]--;
			l[i]--;
		}
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}