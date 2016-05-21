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
struct rec{
	LL x1,x2,y1,y2;
	LL cnt;
	LL x,y;
} a[1010];
int n;
void solve(){
	
	pair<LL, pair<LL,LL> > res = MP(1e18, MP(-1,-1));
	vector<pair<int,int> > aa;
	map<int,int> umap1;
	map<int,int> umap2;
	FOR(i,0,n)
	{
		FORE(j,a[i].x1,a[i].x2)
		FORE(k,a[i].y1,a[i].y2)
		{
			aa.PB(MP(j,k));
			umap1[j]++;
			umap2[k]++;
		}
	}
	map<int,LL> umap11;
	map<int,LL> umap22;
	map<int,int> cnt1;
	map<int,int> cnt2;
	LL last = 0;
	LL last1 = 0;
	ITE(i,umap1)
	{
		umap11[i->first] = last + 1LL * i->second * i->first;
		cnt1[i->first] = last1 + i->second;
		last = umap11[i->first]; 
		last1 = cnt1[i->first];
	}
	last = 0;
	last1 = 0;
	ITE(i,umap2)
	{
		umap22[i->first] = last + 1LL * i->second * i->first;
		cnt2[i->first] = last1 + i->second;
		last = umap22[i->first]; 
		last1 = cnt2[i->first];
	}
	sort(ALL(aa));
	LL tot1 = (--cnt1.end())->second;
	LL tot2 = (--cnt2.end())->second;
	LL sum1 = (--umap11.end())->second;
	LL sum2 = (--umap22.end())->second;
	FOR(i,0,aa.size())
	{
		LL xx = aa[i].first;
		LL yy = aa[i].second;
		LL dist = 0;
		dist += xx * cnt1[xx] - umap11[xx];
		dist += yy * cnt2[yy] - umap22[yy];
		dist += (sum1 - umap11[xx]) - (tot1 - cnt1[xx]) * xx;
		dist += (sum2 - umap22[yy]) - (tot2 - cnt2[yy]) * yy;
		res = min(res, MP(dist, MP(xx, yy)));
	}


	cout << res.second.first << " " << res.second.second << " " << res.first << endl;


}
int main()
{
	int T;
	cin >> T;
	FOR(z, 0, T)
	{
		cin >> n;
		FOR(i,0,n)
		{
			cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		}
		cout << "Case #" << z + 1 << ": ";
		solve();
	}
}