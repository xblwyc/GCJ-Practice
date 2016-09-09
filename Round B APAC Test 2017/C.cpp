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
#define lson(x) x * 2 + 1
#define rson(x) x * 2 + 2
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}

struct node
{
    LL l, r;
    int cnt;
    int flag;
} tree[500100 * 2 * 4];

LL l[500100];
LL r[500100];
LL l1, r1;
LL n, a, b, c1, c2, m;
set<LL> uset;
map<LL,LL > umap;
map<LL,LL> reverseMap;


void pushDown(int index)
{
    if(tree[index].flag)
    {
        tree[index].flag = 0;
        tree[lson(index)].cnt += tree[index].cnt;
        tree[rson(index)].cnt += tree[index].cnt;
        tree[index].cnt = 0;
        tree[lson(index)].flag = tree[rson(index)].flag = 1;
    }
}
void pushUp(int index)
{
    int c = min(tree[lson(index)].cnt, tree[rson(index)].cnt);
    tree[index].cnt += c;
    tree[index].flag = 1;
    tree[lson(index)].cnt -= c;
    tree[rson(index)].cnt -= c;
}
void build(int index, int l, int r)
{
    tree[index].l = l;
    tree[index].r = r;
    tree[index].cnt = 0;
    tree[index].flag = 0;
    if(l + 1 == r)
        return;
    int mid = (l + r) / 2;
    build(lson(index), l, mid);
    build(rson(index), mid, r);
}
void update(int index, int l, int r, int val)
{
    if(tree[index].r < l)
        return;
    if(tree[index].l > r)
        return;
    if(tree[index].r <= r && tree[index].l >= l)
    {
        tree[index].cnt += val;
        tree[index].flag = 1;
        return;
    }
    if(tree[index].l + 1 == tree[index].r)
        return;
    update(lson(index), l , r, val);
    update(rson(index), l , r, val);

}

LL query(int index, int l, int r)
{
    if(tree[index].r < l)
        return 0;
    if(tree[index].l > r)
        return 0;
    if(tree[index].cnt >= 1)
    {
        int L = tree[index].l;
        int R = tree[index].r;
        return reverseMap[R] - reverseMap[L];
    }
    if(tree[index].l + 1 == tree[index].r)
        return 0;
    return query(lson(index), l, r) + query(rson(index), l , r);
}
LL solve()
{
    uset.clear();
    umap.clear();
    reverseMap.clear();
    FOR(i,0,n)
    {
        uset.insert(l[i]);
        uset.insert(r[i]);
    }
    int N = 0;
    ITE(i,uset)
    {
        umap[*i] = N;
        reverseMap[N] = *i;
        N++;
    }
    build(0, 0, N - 1);
    FOR(i,0,n)
    {
        update(0, umap[l[i]], umap[r[i]], 1);
    }
    LL res = INF;
    FOR(i,0,n)
    {
        update(0, umap[l[i]], umap[r[i]], -1);
        res = min(res, query(0, 0, N - 1));
        update(0, umap[l[i]], umap[r[i]], 1);
    }
    return res;

}
int main(){
    int T;
    cin >> T;
    FOR(hh,0,T)
    {
        cin >> n >> l1 >> r1 >> a >> b >> c1 >>c2 >> m;
        l[0] = l1;
        r[0] = r1 + 1;
        for(int i = 1; i < n; i++)
        {
            l[i] = (a * l1 + b * r1 + c1) % m;
            r[i] = (a * r1 + b * l1 + c2) % m;
            l1 = l[i];
            r1 = r[i];
            if(l[i] > r[i])
                swap(l[i], r[i]);
            r[i]++;
        }
        cout << "Case #" << hh + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}