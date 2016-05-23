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

int m, n;
int b[110][110];
int vis[110][110];
int dirx[4] = {0,-1,0,1};
int diry[4] = {1,0,-1,0};
int xa,xb,ya,yb;
bool ok;
pair<int,int> MAX(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first)
    {
        if(a.first < b.first)
            return a;
        return b;
    }
    if(a.second > b.second)
        return a;
    return b;
}
void DFS(int x ,int y)
{
    if(x < 0 || x >= m)
        return ;
    if(y < 0 || y >= n)
        return ;
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    if(b[x][y] == -1)
        return;
    if(x == xb && y == yb)
        ok = true;
    FOR(i,0,4)
    DFS(x + dirx[i], y + diry[i]);
}
pair<int,int> dp[110][110][4];
pair<int,int> rec(int x, int y, int dir)
{
    if(x < 0 || x >= m)
        return MP(INF, 0);
    if(y < 0 || y >= n)
        return MP(INF, 0);
    if(dp[x][y][dir].first != -1)
        return dp[x][y][dir];
    if(x == xa && y == ya)
        return MP(0,b[xa][ya]);
    if(b[x][y] == -1)
        return MP(INF, 0);
    dp[x][y][dir] = MP(INF, 0);
    int oppo = (dir + 2) % 4;
    pair<int,int> res = MP(INF, 0);
    FOR(i,0,4)
    {
        pair<int,int > tmp = rec(x + dirx[dir],y + diry[dir], i);
        res = MAX(res, tmp);
        cout << "cnt" << endl;
    }
    res.first++;
    res.second += b[x][y];
    debug(x,y,dir, res.first, res.second);
    return dp[x][y][dir] = res;
}
int solve()
{
    if(xa == xb && ya == yb)
        return b[xa][ya];

    ZERO(vis);
    ok = false;
    DFS(xa,ya);
    if(!ok)
        return -1;
    FOR(i,0,110)
    FOR(j,0,110)
    FOR(k,0,4)
    dp[i][j][k] = MP(-1,-1);
    pair<int,int> res = MP(INF, 0);
    FOR(i,0,4)
    res = MAX(res,rec(xb,yb, i));
    return res.second;
    
}
int main()
{
    int T;
    cin >> T;
    FOR(z, 0, T)
    {
        cin >> m >> n;
        cin >> xa >> ya >> xb >> yb;
        FOR(i,0,m)
        FOR(j,0,n)
        cin >> b[i][j];
        cout << "Case #" << z + 1 << ": ";
        int res = solve();
        if(res == -1)
            cout << "Mission Impossible." << endl;
        else
            cout << res << endl;
    }
}