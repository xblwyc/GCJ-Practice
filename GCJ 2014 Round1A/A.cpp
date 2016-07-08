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

int n, l;
char c;
string a[200];
string b[200];
int solve()
{
    vector<string> test;
    FOR(i,0,n)
    FOR(j,0,n)
    {
        string tmp;
        FOR(k,0,l)
        {
            if(a[i][k] == b[j][k])
                tmp.PB('0');
            else
                tmp.PB('1');
        }
        test.PB(tmp);
    }
    int res = INF;
    FOR(i,0,test.size())
    {
        int cnt = 0;
        FOR(j,0,l)
        {
            if(test[i][j] == '1')
                cnt++;
        }
        vector<string> bb;
        FOR(j,0,n)
        {
            string tmp;
            FOR(k,0,l)
            {
                tmp.PB((a[j][k] - '0') ^ (test[i][k] - '0') + '0');
            }
            bb.PB(tmp);
        }
        sort(ALL(bb));
        bool flag = true;
        FOR(j,0,n)
        {
            if(bb[j] != b[j])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            res = min(res, cnt);
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> n >> l;
        FOR(i,0,n)
        {
            string tmp;
            cin >> tmp;
            a[i] = tmp;
        }
        FOR(i,0,n)
        {
            string tmp;
            cin >> tmp;
            b[i] = tmp;
        }
        sort(b, b + n);
        cout << "Case #" << hh + 1 << ": ";
        int res = solve();
        if(res == INF)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << res << endl;
    }
    return 0;
}