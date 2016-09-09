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

LL a, b, n, k;
LL f[100100];
LL x[100100];
LL y[100100];
LL fastPow(LL val, LL exp)
{
    if(exp == 0)
        return 1LL;
    LL res = fastPow(val, exp / 2);
    res *= res;
    res %= k;
    if(exp % 2)
        res *= val;
    res %= k;
    return res;
}
LL solve()
{
    if(k == 1)
    {
        LL tmp = 1LL * (n % MOD) * ((n - 1) % MOD);
        return tmp % MOD;
    }
    ZERO(x);
    ZERO(y);
    ZERO(f);
    if(n < k)
    {
        FORE(i,1,n)
        f[i] = 1;
    }
    else
    {
        f[0] = 1LL * n / k;
        for(int i = 1; i < k; i++)
            f[i] = 1LL * (n - i) / k + 1;
    }
    LL res = 0;
    FOR(i,0,k)
    {
        if(f[i] == 0)
            continue;
        LL v1 = fastPow(i, a);
        LL v2 = fastPow(i, b);
        if((v1 + v2) % k == 0)
            res -= f[i];
        x[v1] += f[i];
        y[v2] += f[i];
        x[v1] %= MOD;
        y[v2] %= MOD;
    }
    res += x[0] * y[0];
    res %= MOD;
    FOR(i,1,k)
    {
        res += x[i] * y[k - i];
        if(res >= MOD)
        res %= MOD;
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> a >> b >> n >> k;
        cout << "Case #" << hh + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}