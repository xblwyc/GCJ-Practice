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
string dir;
int b[25][25];
vector<pair<int, int> > store[25];
int res[25][25];
void init()
{
	if(dir == "left")
	{
		FOR(i,0,n)
		{
			vector<pair<int,int> > & arr = store[i];
			for(int j = n - 1; j >= 0; j--)
			{
				if(b[i][j] == 0)
					continue;
				if(arr.size() == 0 || b[i][j] != arr.back().first)
					arr.PB(MP(b[i][j], 1));
				else
					arr.back().second++;
			}
		}
	}
	else if(dir == "right")
	{
		FOR(i,0,n)
		{
			vector<pair<int,int> > & arr = store[i];
			FOR(j,0,n)
			{

				if(b[i][j] == 0)
					continue;
				if(arr.size() == 0 || b[i][j] != arr.back().first)
					arr.PB(MP(b[i][j], 1));
				else
					arr.back().second++;
			}
		}
	}
	else if(dir == "down")
	{
		FOR(j,0,n)
		{
			vector<pair<int,int> > & arr = store[j];

			FOR(i,0,n)
			{

				if(b[i][j] == 0)
					continue;
				if(arr.size() == 0 || b[i][j] != arr.back().first)
					arr.PB(MP(b[i][j], 1));
				else
					arr.back().second++;
			}
		}
	}
	else
	{
		FOR(j,0,n)
		{
			vector<pair<int,int> > & arr = store[j];
			for(int i = n - 1;i >= 0; i--)
			{

				if(b[i][j] == 0)
					continue;	
				if(arr.size() == 0 || b[i][j] != arr.back().first)
					arr.PB(MP(b[i][j], 1));
				else
					arr.back().second++;
			}
		}
	}
}
void solve()
{
	FOR(i,0,n)
	store[i].clear();
	init();
	if(dir == "right")
	{
		FOR(i,0,n)
		{
			vector<pair<int,int> > & arr = store[i];
			for(int j = n - 1; j >= 0; j--)
			{
				if(arr.size() == 0)
					res[i][j] = 0;
				else
				{
					int num = arr.back().first;
					int cnt = arr.back().second;
					if(cnt > 1)
					{
						res[i][j] = num * 2;
						arr.back().second -= 2;
					}
					else
					{
						res[i][j] = num;
						arr.back().second--;
					}
					if(arr.back().second == 0)
						arr.pop_back();
				}
			}
		}
	}
	else if(dir == "left")
	{
		FOR(i,0,n)
		{
			vector<pair<int,int> > & arr = store[i];
			FOR(j,0,n)
			{
				if(arr.size() == 0)
					res[i][j] = 0;
				else
				{
					int num = arr.back().first;
					int cnt = arr.back().second;
					if(cnt > 1)
					{
						res[i][j] = num * 2;
						arr.back().second -= 2;
					}
					else
					{
						res[i][j] = num;
						arr.back().second--;
					}
					if(arr.back().second == 0)
						arr.pop_back();
				}
			}
		}
	}
	else if(dir == "up")
	{
		FOR(j,0,n)
		{
			vector<pair<int,int> > & arr = store[j];

			FOR(i,0,n)
			{
				if(arr.size() == 0)
					res[i][j] = 0;
				else
				{
					int num = arr.back().first;
					int cnt = arr.back().second;
					if(cnt > 1)
					{
						res[i][j] = num * 2;
						arr.back().second -= 2;
					}
					else
					{
						res[i][j] = num;
						arr.back().second--;
					}
					if(arr.back().second == 0)
						arr.pop_back();
				}
			}
		}
	}
	else
	{
		FOR(j,0,n)
		{
			vector<pair<int,int> > & arr = store[j];
			for(int i = n - 1;i >= 0; i--)
			{
				if(arr.size() == 0)
					res[i][j] = 0;
				else
				{
					int num = arr.back().first;
					int cnt = arr.back().second;
					if(cnt > 1)
					{
						res[i][j] = num * 2;
						arr.back().second -= 2;
					}
					else
					{
						res[i][j] = num;
						arr.back().second--;
					}
					if(arr.back().second == 0)
						arr.pop_back();
				}
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		cin >> dir;
		FOR(i,0,n)
		FOR(j,0,n)
		cin >> b[i][j];
		cout << "Case #" << z + 1 << ":" << endl;
		solve();
		FOR(i,0,n)
		{
			FOR(j,0,n)
			cout << res[i][j] << " ";
			cout << endl;
		}
	}
}