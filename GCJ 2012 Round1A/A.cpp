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

int a,b;
LD p[100100];
LD c[100100];
LD solve()
{
    ZERO(c);
    c[0] = 0;
    
    FORE(i,1,a)
    {
        c[i] = 1 - p[i - 1] + p[i - 1] * c[i - 1];
        //c[i] = (c[i - 1] + (1 - c[i - 1]) * (1- p[i - 1]));
    }
    LD res = b + 2;
    FORE(i,0,a)
    {
        LD val = (b - a + 1 + 2 * i) + c[a - i] * (b + 1);
        //LD val = (1 - c[a - i]) * (b - a + 1 + 2 * i) + c[a - i] * (2 * b - a + 2 + 2 * i);
        res = min(val, res);
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    cout << fixed;
    cout << setprecision(15);
    FOR(hh,0,T)
    {
        cin >> a >> b;
        FOR(i,0,a)
        cin >> p[i];
        cout << "Case #" << hh + 1 << ": " << endl;
        cout << solve() << endl;
    }
    return 0;
}