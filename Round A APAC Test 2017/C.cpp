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

int n;
LL a[110];
void div(LD &val, LL cnt, LD num)
{
    if(cnt > 0)
    {
        FOR(i,0,cnt)
        val *= num;
    }
    else if(cnt < 0)
    {
        cnt *= -1;
        FOR(i,0,cnt)
        val /= num;
    }
}
LD calc(LD val)
{
    LD res = 0;
    FOR(i,0,n + 1)
    {
        LD tmp = a[i];
        div(tmp, (n - 100) - i, val);
        res += tmp;
    }
    return res;
}
LD solve()
{
    LL tot = 0;
    FOR(i,0,n + 1)
    tot += a[i];
    if(tot == 0)
        return 0;
    LD sum = 0;
    FOR(i,0,n + 1)
    {
        LD tmp = a[i];
        div(tmp, (n - 100) - i, 2);
        sum += tmp;
    }
    LD low = 0;
    LD high = 2;
    FOR(i,0,200)
    {
        LD mid = (low + high) / 2;
        LD val = calc(mid);
        if(val > 0)
        {
            if(sum > 0)
            {
                high = mid;
            }
            else
                low = mid;
        }
        else
        {
            if(sum > 0)
                low = mid;
            else
                high = mid;
        }
    }
    return low - 1;
}
int main(){
    int T;
    cout << fixed;
    cout << setprecision(15);
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> n;
        FOR(i,0,n + 1)
        cin >> a[i];
        a[0] *= -1;
        cout << "Case #" << hh + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}