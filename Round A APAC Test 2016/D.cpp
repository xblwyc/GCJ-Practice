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


int m,n,s;
pair<int, char> ops[100100];
int dirx[4] = {0,1,0,-1};
int diry[4] = {1,0,-1,0};
deque<pair<int,int> > deq;
set<pair<int,int> > snake;
set<pair<int,int> > food;
int x,y,dir,p;
bool stop;
void proc()
{
	if(dir < 0 || dir >= 4)
	{
		dir += 4;
		dir %= 4;
	}
	int nx = deq.front().first + dirx[dir];
	int ny = deq.front().second + diry[dir];
	if(nx < 0 || nx >= m)
	{
		nx += m;
		nx %= m;
	}
	if(ny < 0 || ny >= n)
	{
		ny += n;
		ny %= n;
	}
	if(deq.back() != MP(nx,ny) && snake.count(MP(nx,ny)))
	{
		stop = true;
		return;
	}
	if((nx + ny) % 2 != 0)
	{
		if(food.count(MP(nx,ny)) == 0)
		{
			snake.insert(MP(nx,ny));
			deq.push_front(MP(nx,ny));
			food.insert(MP(nx,ny));
			return;
		}
	}
	int tailx = deq.back().first;
	int taily = deq.back().second;
	snake.insert(MP(nx,ny));
	deq.push_front(MP(nx,ny));
	snake.erase(MP(tailx,taily));
	deq.pop_back();
}
LL solve()
{
	p = x = y = dir = 0;
	stop = false;
	snake.clear();
	food.clear();
	deq.clear();
	deq.push_back(MP(0,0));
	snake.insert(MP(0,0));
	FOR(i,1,ops[s - 1].first + 2 * m + 2 * n + 10)
	{
		proc();
		if(stop)
			break;
		if(p < s && ops[p].first == i)
		{
			char op = ops[p].second;
			if(op == 'L')
				dir--;
			else
				dir++;
			p++;
		}
	}
	return deq.size();
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> s >> m >> n;
		FOR(i,0,s)
		cin >> ops[i].first >> ops[i].second;
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}