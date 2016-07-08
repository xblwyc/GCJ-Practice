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

int n, x, y;
vector<int> node[1010];
int vis[1010];
int num[1010];
int cnt;
int dfs(int index)
{
    if(vis[index])
    return 0;
    vis[index] = 1;
    int res = 0;
    FOR(i,0,node[index].size())
    {
        res += dfs(node[index][i]);
    }
    return num[index] = res + 1;
}
int check(int index)
{
    if(vis[index])
        return 0;
    vis[index] = 1;
    vector<int> child;
    FOR(i,0,node[index].size())
    {
        if(!vis[node[index][i]])
            child.PB(node[index][i]);
    }
    //debug(child.size(), index)
    if(child.size() == 0)
        return 0;
    if(child.size() == 1)
        return num[child[0]];
    vector<int> res;
    int tot = 0;
    FOR(i,0,child.size())
    {
        tot += num[child[i]];
    }
    FOR(i,0,child.size())
    {
        res.PB(num[child[i]] - check(child[i]));
        if(res.size() > 2)
        {
            sort(ALL(res), greater<int>());
            res.pop_back();
        }
    }
   // debug(index, tot - (res[0] + res[1]));
    return tot - (res[0] + res[1]);
}
int solve()
{
    int res = INF;
    FOR(i,0,n)
    {
        ZERO(vis);
        NEG(num);
        dfs(i);
        ZERO(vis);
        //debug(i, check(i));
        res = min(res, check(i));
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> n;
        FOR(i,0,1010)
        node[i].clear();
        FOR(i,0,n - 1)
        {
            cin >> x >> y;
            x--;y--;
            node[x].PB(y);
            node[y].PB(x);
        }
        cout << "Case #" << hh + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}