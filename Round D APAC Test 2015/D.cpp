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
char b[10][10];
int dirx[8] = {-1,0,1,1,1,0,-1,-1};
int diry[8] = {1,1,1,0,-1,-1,-1,0};
int dirxx[8] = {2,2,1,1,-2,-2,-1,-1};
int diryy[8] = {-1,1,-2,2,-1,1,-2,2};
bool valid(int x,int y)
{
	if(x < 0 || x >= 8)
		return false;
	if(y < 0 || y >= 8)
		return false;
	return true;
}
LL solve()
{
	LL res = 0;
	FOR(i,0,8)
	FOR(j,0,8)
	{
		if(b[i][j] == 'K')
		{
			FOR(k,0,8)
			{
				int nx = i + dirx[k];
				int ny = j + diry[k];
				if(nx < 0 || nx >= 8)
					continue;
				if(ny < 0 || ny >= 8)
					continue;
				if(b[nx][ny] != ' ')
					res++;
			}
		}
		else if(b[i][j] == 'Q')
		{
			FOR(k,0,8)
			{
				int x = i + dirx[k];
				int y = j + diry[k];
				int cnt = 0;
				while(valid(x, y))
				{
					if(b[x][y] != ' ')
					{
						cnt = 1;
						break;
					}
					x += dirx[k];
					y += diry[k];
				}
				res += cnt;

			}
		}
		else if(b[i][j] == 'R')
		{
			FOR(k,0,8)
			{
				if(k % 2 == 0)
					continue;
				int x = i + dirx[k];
				int y = j + diry[k];
				int cnt = 0;
				while(valid(x, y))
				{
					if(b[x][y] != ' ')
					{
						cnt = 1;
						break;
					}
					x += dirx[k];
					y += diry[k];
				}
				res += cnt;
			}
		}
		else if(b[i][j] == 'B')
		{
			FOR(k,0,8)
			{
				if(k % 2 != 0)
					continue;
				int x = i + dirx[k];
				int y = j + diry[k];
				int cnt = 0;
				while(valid(x, y))
				{
					if(b[x][y] != ' ')
					{
						cnt = 1;
						break;
					}
					x += dirx[k];
					y += diry[k];
				}
				res += cnt;
			}
		}
		else if(b[i][j] == 'N')
		{
			FOR(k,0,8)
			{
				int nx = i + dirxx[k];
				int ny = j + diryy[k];
				if(!valid(nx, ny))
					continue;
				if(b[nx][ny] != ' ')
					res++;
			}
		}
		else if(b[i][j] == 'P')
		{
			FOR(k,0,8)
			{
				if(!(k == 2 || k == 4))
					continue;
				int x = i + dirx[k];
				int y = j + diry[k];
				if(!valid(x,y))
					continue;
				if(b[x][y] != ' ')
					res++;
			}
		}
	}
	return res;
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		FOR(i,0,8)
		FOR(j,0,8)
		b[i][j] = ' ';
		FOR(i,0,n)
		{
			string x;
			cin >> x;
			b[x[0]- 'A'][x[1] - '1'] = x.back();
		}
		cout << "Case #" << z + 1 << ": ";
		cout << solve() << endl;
	}
}