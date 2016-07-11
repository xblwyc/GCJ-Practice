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

int m, n;
int b[55][55];
int vis[55][55];
int h[55][55];
bool flag;
int dirx[4] = {0, -1, 0 , 1};
int diry[4] = {1, 0, -1, 0};
void DFS(int x, int y, int val)
{
    if(x < 0 || x >= m || y < 0 || y >= n)
        return;
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    if(x == 0 || y == 0 || x == m - 1 || y == n - 1)
    {
        if(b[x][y] < val)
        {
            //debug(x, y, val);
            flag = false;
        }
        return;
    }
    FOR(i,0,4)
    {
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if(nx < 0 || nx >= m)
            continue;
        if(ny < 0 || ny >= n)
            continue;
        if(b[nx][ny] >= val)
            continue;
        DFS(x + dirx[i], y + diry[i], val);
    }
}
bool valid(int val ,int x ,int y)
{
    ZERO(vis);
    flag = true;
    DFS(x, y, val);
    //debug(x, y, val, flag);
    return flag;
}
LL solve()
{
    FUL(h);
    LL res = 0;
    FOR(i,0,m)
    FOR(j,0,n)
    {
        int low = b[i][j];
        int high = 1010;
        while(low < high)
        {
            int mid = (low + high + 1) / 2;
            if(valid(mid, i, j))
                low = mid;
            else
                high = mid - 1;
        }
        res += (low - b[i][j]);
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> m >> n;
        FOR(i,0,m)
        FOR(j,0,n)
        cin >> b[i][j];
        cout << "Case #" << hh + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}