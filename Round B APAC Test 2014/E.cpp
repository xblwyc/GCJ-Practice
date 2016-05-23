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

string a[100100];
int cnt;
void solve()
{
	string tmp;
	vector<string> out;
	stack<pair<int,int> > sta;
	pair<int,int> last = MP(-100,-100);
	FOR(i,0,cnt)
	{
		if(a[i].size() == 0)
		{
			if(sta.size() == 0)
			{
				out.PB(tmp);
				tmp.clear();
			}
			continue;
		}
		FORE(j,0,a[i].size())
		{
			debug(i,j,tmp)
			if(j == 0)
			{
				if(sta.size() == 0)
					tmp.PB(a[i][j]);
			}
			else if(j == a[i].size())
			{
				if(sta.size() == 0)
				{
					out.PB(tmp);
					tmp.clear();
				}
			}
			else{
				if(a[i][j - 1] == '*' && a[i][j] == '/')
				{
					if(sta.size() && !(sta.top().first == i && sta.top().second == j - 1))
					{
						sta.pop();
						last = MP(i,j);
					}
					else if(sta.size() == 0)
						tmp.PB(a[i][j]);

				}
				else if(a[i][j - 1] == '/' && a[i][j] == '*')
				{
					if(!(last.first == i && last.second == j - 1))
					{
						if(sta.size() == 0)
							tmp.pop_back();
						sta.push(MP(i,j));
					}
					else if(sta.size() == 0)
						tmp.PB(a[i][j]);
				}
				else if(sta.size() == 0)
					tmp.PB(a[i][j]);
			}
		}
	}
	if(tmp.size())
	out.PB(tmp);
	FOR(i,0,out.size())
	cout << out[i] << endl;
}
int main()
{
	string s;
	cnt = 0;
	while(getline(cin, s))
	{
		a[cnt++] = s;
	}
	cout << "Case #1:" << endl;
	solve(); 
}