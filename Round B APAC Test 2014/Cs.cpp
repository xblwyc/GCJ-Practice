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
int vis[110];
int solve()
{
	ZERO(vis);
	FOR(j,0,n)
	{
		queue<pair<int,int> > q;
		FOR(i,0,n)
		{
			if(vis[i])
				continue;
			if(q.size() == 2 && q.front().first == q.back().first && q.front().first == a[i])
			{
				vis[q.front().second] = vis[q.back().second] = vis[i] = 1;
				break;
			}
			else
			{
				q.push(MP(a[i], i));
				if(q.size() > 2)
					q.pop();
			}
		}
	}
	int res = 0;
	FOR(i,0,n)
	if(!vis[i])
	{
		res++;
	}
	return res;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n >> k;
		FOR(i,0,n)
		cin >> a[i];
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}