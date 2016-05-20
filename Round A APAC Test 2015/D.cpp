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

LL n,m;
LL s[510];
vector<pair<int,int> > a;
int remain;
void rec(int w, int h)
{
	if(w > h)
		swap(w,h);
	int i;
	for(i = a.size() - 1; i >= 0; i--)
		if(a[i].second > 0 && (1LL << a[i].first) <= w)
			break;
	if(i < 0)
		return;
	remain--;
	a[i].second--;
	LL l = (1LL << a[i].first);
	rec(w - l, l);
	rec(w, h - l);
}
int solve()
{
	sort(s, s+ n);
	remain = n;
	a.clear();
	FOR(i,0,n)
	{
		if(a.size() == 0 || a.back(). first != s[i])
			a.PB(MP(s[i], 1));
		else
			a.back().second++;
	}
	int cnt = 0;
	FOR(i,0,n)
	{
		if(remain > 0)
		{
			cnt++;
			rec(m,m);
		}
	}
	return cnt;

}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n >> m;
		FOR(i,0,n)
		cin >> s[i];
		cout << "Case #" << z + 1 << ": 	";
		cout << solve() << endl;
	}
}