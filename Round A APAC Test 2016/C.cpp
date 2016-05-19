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

int n,m;
struct edge
{
	int u,v,c;
	int index;
} e[10010];
bool comp(edge a, edge b)
{
	return a.c < b.c;
}
LL dist[110][110];
int inque[110];
void solve()
{
	sort(e,e + m, comp);
	FUL(dist);
	vector<int> res;
	FOR(i,0,n)
	dist[i][i] = 0;
	queue<pair<int,int> > q;
	FOR(i,0,m)
	{
		int u = e[i].u;
		int v = e[i].v;
		if(dist[u][v] < e[i].c)
		{
			res.PB(e[i].index);
			continue;
		}
		dist[u][v] = dist[v][u] = e[i].c;
		FOR(j,0,n)
		FOR(k,0,n)
		{
			dist[u][k] = dist[k][u] = min(dist[u][k], dist[u][j] + dist[j][k]);
			dist[v][k] = dist[k][v] = min(dist[v][k], dist[v][j] + dist[j][k]);
		}
		FOR(j,0,n)
		FOR(k,0,n)
		{
			dist[k][j] = dist[j][k] = min(dist[j][k], min(dist[j][u] + dist[u][k], dist[j][v] + dist[v][k]));
		}
	}
	sort(ALL(res));
	FOR(i,0,res.size())
	cout << res[i] << endl;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n >> m;
		FOR(i,0,m)
		{
			e[i].index=  i;
			cin >> e[i].u >> e[i].v >> e[i].c;
		}
		cout << "Case #" << z + 1 << ":" << endl;
		solve();
	}
}