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

struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};
vector<Edge> edges;
vector<int> G[100100]; // 每个节点出发的边编号
void addEdge(int u, int v, int w)
{
    int index = edges.size();
    edges.PB(Edge(u,v,w));
    G[u].PB(index);
}
int n,m,q;
int sn[110];
int w[110];
int t[110][1010];
struct tunnel
{
	int xa,ya,xb,yb,t;
} tun[110];
int xa,xb,ya,yb;
int conv(int x ,int y)
{
	return (x - 1) * 1010 + y;
}
void solve()
{
	FORE(i,1,n)
	{
		FORE(j,1,sn[i] - 1)
		{
			int tot = 0;
			FORE(k, j, sn[i] - 1)
			{
				tot += t[i][k];
				addEdge(conv(i,j), conv(i, k + 1), tot + w[i]);
				addEdge(conv(i, k + 1), conv(i, j), tot + w[i]);
			}
		}
	}
	FOR(i,0,m)
	{
		addEdge(conv(tun[i].xa, tun[i].ya), conv(tun[i].xb, tun[i].yb),tun[i].t );		
		addEdge(conv(tun[i].xb, tun[i].yb), conv(tun[i].xa, tun[i].ya), tun[i].t );
	}
}
int in_queue[100100];
int cnt[100100];
int d[100100];
bool query(int s)
{
    int u;
    queue<int> Q;
    memset(in_queue, 0, sizeof(in_queue));
    memset(cnt, 0, sizeof(cnt));
    NEG(d);
    
    d[s] = 0;
    in_queue[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        in_queue[u=Q.front()] = false;
        Q.pop();
        for (int i=0; i<G[u].size(); ++i) {
            Edge &e = edges[G[u][i]];
            if (d[e.to] == -1 || d[e.to] > d[u] + e.weight) {
                d[e.to] = d[u] + e.weight;
                if (!in_queue[e.to]) {
                    Q.push(e.to);
                    in_queue[e.to] = true;
                    if (++cnt[e.to] > n)
                        return false;
                }
            }
        }
    }
    return true;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		edges.clear();
		FOR(i,0,100100)
		G[i].clear();
		cin >> n;
		FORE(i,1,n)
		{
			cin >> sn[i] >> w[i];
			FORE(j,1,sn[i] - 1)
			{
				cin >> t[i][j];
			}
		}
		cin >> m;
		FOR(i,0,m)
		cin >> tun[i].xa >> tun[i].ya >> tun[i].xb >> tun[i].yb >> tun[i].t;
		solve();
		cin >> q;
		cout << "Case #" << z + 1 << ":" << endl;
		FOR(i,0,q)
		{
			cin >> xa >> ya >> xb >> yb;
			query(conv(xa,ya));
			cout << d[conv(xb,yb)] << endl;
		}
	}
}