#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<complex>
#include<list>
#include<set>
#include<assert.h>
#include<bitset>
#define sl ch[rt][0]
#define sr ch[rt][1]
#define inf 1000000000
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
#define ll long long
const int maxn = 200000;
const int mod = 1e9+7;
int pow_mod(int a,int n,int mod){
    int r = 1 % mod;
    while(n){
        if(n&1) r=(ll)r*a%mod;
        a=(ll)a*a%mod;
        n>>=1;
    }
    return r;
}
int num[maxn];
int tow[maxn];
int main()
{
    int T,a,b,CASE=0,k;
    ll n;
    cin>>T;
    while(T --){
        cin>>a>>b>>n>>k;
        memset(num,0,sizeof num);
        int c;ll d;
        for(int i=0;i<k;i++){
            tow[i] = c = pow_mod(i,a,k);
            num[c] = (num[c] + n/k + (i&&n%k>=i) )%mod;
        }
        int ans = 0;
        for(int i=0;i<k;i++){
            c = pow_mod(i,b,k);
            d = (n/k+ (i&&n%k>=i)) % mod;
            ll t = d*((k-c)%k==tow[i]?num[(k-c)%k]-1:num[(k-c)%k])%mod;
            t=(t%mod+mod)%mod;
            ans = (ans+t)%mod;
        }
        cout<<"Case #"<<++CASE<<": "<<ans<<endl;
    }
    return 0;
}

