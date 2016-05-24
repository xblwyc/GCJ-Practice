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

int n;
int b[310][310];
int vis[310][310];
int dirx[8] = {1,1,1,0,0,-1,-1,-1};
int diry[8] = {-1,0,1,-1,1,-1,0,1};
bool valid(int x ,int y)
{
	if(x < 0 || x >= n || y < 0 || y >= n)
		return false;
	return true;
}
void DFS(int x ,int y)
{
	if(vis[x][y])
		return;
	vis[x][y] = 1;
	if(b[x][y] != 0)
		return;
	FOR(i,0,8)
	{
		int nx = x + dirx[i];
		int ny = y + diry[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		DFS(nx,ny);
	}
}
int solve()
{
	LL res = 0;
	ZERO(vis);
	FOR(i,0,n)
	FOR(j,0,n)
	{
		if(b[i][j] == -1)
			continue;
		int cnt = 0;
		FOR(k,0,8)
		{
			int nx = i + dirx[k];
			int ny = j + diry[k];
			if(!valid(nx,ny))
				continue;
			if(b[nx][ny] == -1)
			cnt++;
		}
		b[i][j] = cnt;
	}
	FOR(i,0,n)
	FOR(j,0,n)
	{
		if(b[i][j] == 0 && !vis[i][j])
		{
			res++;
			DFS(i,j);
		}
	}
	FOR(i,0,n)
	FOR(j,0,n)
	if(!vis[i][j] && b[i][j] != -1	)
		res++;
	return res;

}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		char c;
		FOR(i,0,n)
		FOR(j,0,n)
		{
			cin >> c;
			if(c == '*')
			b[i][j] = -1;
			else
			b[i][j] = -2; 
		}
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}