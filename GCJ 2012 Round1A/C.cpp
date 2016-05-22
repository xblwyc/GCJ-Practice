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
LL a[510];
vector<LL> aa[10001000];
int cnt;
void init()
{
    cnt = 0;
    FOR(i,0,n)
    FOR(j,i + 1, n)
    FOR(k,j + 1, n)
    FOR(p,k + 1, n)
    FOR(q,p + 1, n)
    {
        if(cnt >= 1e7 + 10)
            return;
        aa[cnt].clear();
        aa[cnt] = vector<LL>({a[i],a[j],a[k],a[p],a[q]});
        cnt++;
    }
}
map<LL, int> umap;
void solve()
{
    init();
    umap.clear();
    FOR(i,0,cnt)
    {
        LL val = 0;
        FOR(j,0,aa[i].size())
        val += aa[i][j];
        if(umap.count(val) == 0)
        {
            umap[val] = i;
        }
        else
        {
            vector<LL> tmp = aa[umap[val]];
            sort(ALL(tmp));
            vector<LL> tmp2 = aa[i];
            sort(ALL(tmp2));
            if(tmp != tmp2)
            {
                FOR(k,0,tmp.size())
                {
                    cout << tmp[k] << " ";
                }
                cout << endl;
                FOR(k,0,tmp2.size())
                {
                    cout << tmp2[k] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
}
int main(){
    int T;
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> n;
        FOR(i,0,n)
        cin >> a[i];
        cout << "Case #" << hh + 1 << ": " << endl;
        solve();
    }
    return 0;
}