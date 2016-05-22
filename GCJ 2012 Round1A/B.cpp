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
#define LD long double
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

long double dp[110][110];
int c[110][110];
int f[110][110];
int h, m, n;
int dirx[4] = {-1,0,0,1};
int diry[4] = {0,-1,1,0};
int flag[110][110];
void update(int x, int y, LD val)
{
    LD water = h - val * 10;
    FOR(i,0,4)
    {
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if(nx < 0 || nx >= m)
            continue;
        if(ny < 0 || ny >= n)
            continue;
        if(c[nx][ny] - f[x][y] < 50 || c[x][y] - f[nx][ny] < 50 || c[nx][ny] - f[nx][ny] < 50)
            continue;
        LD extra = 0;
        if(c[nx][ny] - water < 50)
        {
            extra = (water - (c[nx][ny] - 50)) / 10;
        }
        LD add = (water - 10 * extra - f[x][y] >= 20)? 1 : 10;

        dp[nx][ny] = min(dp[nx][ny], val + add + extra);
        
    }
}
void DFS(int x,int y)
{
    if(flag[x][y])
        return;
    flag[x][y] = 1;
    dp[x][y] = 0;
    int maxLevel = max(h, f[x][y]);
    FOR(i,0,4)
    {
        int nx = dirx[i] + x;
        int ny = diry[i] + y;
        if(nx < 0 || nx >= m)
            continue;
        if(ny < 0 || ny >= n)
            continue;
        if(c[nx][ny] - maxLevel < 50 || c[x][y] - f[nx][ny] < 50 || c[nx][ny] - f[nx][ny] < 50)
            continue;
        DFS(nx,ny);
    }
}
LD solve()
{
    FOR(i,0,110)
    FOR(j,0,110)
    dp[i][j] = INF;
    dp[0][0] = 0;
    ZERO(flag);
    DFS(0,0);
    ZERO(flag);
    FOR(c,0,m*n)
    {
        int x = -1;
        int y = -1;
        LD curr = INF;
        FOR(i,0,m)
        FOR(j,0,n)
        {
            if(!flag[i][j] && dp[i][j] <= curr)
            {
                curr = dp[i][j];
                x = i;
                y = j;
                
            }
        }
        flag[x][y] = 1;
        if(x == m - 1 && y == n - 1)
            return curr;
        update(x,y,curr);
        
    }
    return dp[m - 1][n - 1];
}
int main(){
    int T;
    cout << fixed;
    cout << setprecision(15);
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> h >> m >> n;
        FOR(i,0,m)
        FOR(j,0,n)
        cin >> c[i][j];
        FOR(i,0,m)
        FOR(j,0,n)
        cin >> f[i][j];
        cout << "Case #" << hh + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}