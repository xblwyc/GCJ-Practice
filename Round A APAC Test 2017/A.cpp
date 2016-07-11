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
string a[110];
char buff[25];
bool cmp(pair<int, string> aa, pair<int, string> bb)
{
    if(aa.first == bb.first)
    {
        return aa.second < bb.second;
    }
    return aa.first > bb.first;
}
string solve()
{
    string res;
    vector<pair<int, string> > aa;
    FOR(i,0,n)
    {
        set<char> uset;
        FOR(j,0,a[i].size())
        {
            if(a[i][j] != ' ')
                uset.insert(a[i][j]);
        }
        aa.PB(MP(uset.size(), a[i]));
    }
    sort(ALL(aa), cmp);
    return aa[0].second;
}
int main(){
    int T;
    cin >> T;
    FOR(hh,0,T)
    {
        string tmp;
        cin >> n;
        getline(cin, tmp);
        FOR(i,0,n)
            getline(cin, a[i]);
        cout << "Case #" << hh + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}