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
struct node
{
	string s1;
	string s2;
	int v;
} a[5010];
map<string, int> umap;
set<string> uset;
vector<pair<int,int> > g[10010];
void init()
{
	uset.clear();
	umap.clear();
	FOR(i,0,10010)
	g[i].clear();
	FOR(i,0,n)
	{
		uset.insert(a[i].s1);
		uset.insert(a[i].s2);
	}
	int cnt = 0;
	ITE(i,uset)
		umap[*i] = cnt++;
	FOR(i,0,n)
	{
		int i1 = umap[a[i].s1];
		int i2 = umap[a[i].s2];
		g[i1].PB(MP(i2, a[i].v));
		g[i2].PB(MP(i1, a[i].v));
	}
}
string q1,q2;
struct node1
{
	int index, statu, tot;
};

queue<node1> q;
int vis[10010][2];
int check(int s, int t)
{
	while(q.size())
		q.pop();
	q.push(node1{s,0,0});
	ZERO(vis);
	while(q.size())
	{
		int index = q.front().index;
		int statu = q.front().statu;
		int tot = q.front().tot;
		q.pop();
		vis[index][statu] = 1;
		if(index == t && statu)
			return tot;
		FOR(i,0,g[index].size())
		{
			int v = g[index][i].first;
			int w = g[index][i].second;
			if(vis[v][statu ^ 1])
				continue;
			int tot1 = tot;
			if(statu == 0)
				tot1 += w;
			else
				tot1 -= w;
			q.push(node1{v, statu ^ 1, tot1});
		}
	}
	return -1;
}
void solve()
{
	if(uset.count(q1) == 0 || uset.count(q2) == 0)
		return;
	int s = umap[q1];
	int t = umap[q2];
	int val1 = check(s,s);
	int val2 = check(t,t);
	int val3 = check(s,t);
	if(val1 != -1 && val2 != -1)
	{
		cout << q1 <<"+" <<q2 <<"="<< (val1 + val2) / 2 << endl;
		return;
	}
	if(val3 != -1)
		cout << q1 <<"+" <<q2 <<"="<< val3 << endl;

}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		string s;
		FOR(i,0,n)
		{
			cin >> s;
			FOR(j,0,s.size())
			{
				if(s[j] == '+' || s[j] == '=')
					s[j] = ' ';
			}
			stringstream ss(s);
			ss >> a[i].s1 >> a[i].s2 >> a[i].v;
		}
		init();
		cout << "Case #" << z + 1 << ":" << endl;
		cin >> m;
		FOR(i,0,m)
		{
			cin >> s;
			FOR(j,0,s.size())
			if(s[j] == '+')
				s[j] = ' ';
			stringstream ss(s);
			ss >> q1 >> q2;
			solve();
		}
	}
}