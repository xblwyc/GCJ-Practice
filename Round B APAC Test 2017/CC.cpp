#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

#define P 1005
#define INF  0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define LL  long long
#define ULL unsigned long long
#define MOD 1000000007

#define eps 1e-9
#define PI acos(-1.0)
#define MID ((l + r)/2)
#define lx (x<<1)
#define rx ((x<<1)|1)

#define ppi pair<int,int>
#define lowbit(x) (x&(-x))
#define REP(i,n) for(int i=0;i<n;i++ )
#define REP_1(i,n) for(int i=1;i<=n;i++ )
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define DWN(i, b, a) for (int i=b-1;i>=a;--i)
#define FOR_1(i, a, b) for (int i=a;i<=b;++i)
#define DWN_1(i, b, a) for (int i=b;i>=a;--i)
#define RST(A) memset(A, 0, sizeof(A))
#define FLC(A, x) memset(A, x, sizeof(A))

LL N, L1, R1, A, B, C1, C2;

LL M;

#define NUM 500005

LL x[NUM * 2];
LL y[NUM * 2];

LL diffXs[NUM * 2];

LL add[NUM * 2];
LL cover[NUM * 2];
LL prefixSum[NUM * 2];

LL solve(){
    
    cin>>N>>L1>>R1>>A>>B>>C1>>C2>>M;

    x[0] = L1;
    y[0] = R1;

    int diffNum = 0;

    for(int i = 1;i<N;i++){
        x[i] = (A * x[i-1] + B * y[i-1] + C1) % M;
        y[i] = (A * y[i-1] + B * x[i-1] + C2) % M;
    }

    for(int i = 0;i<N;i++){

        //diffXs[diffNum++] = min(x[i],y[i]);

        //diffXs[diffNum++] = max(x[i],y[i])+1;
        if(x[i]>y[i]) {
            swap(x[i],y[i]);
        }
        
        diffXs[diffNum++] = x[i];
        diffXs[diffNum++] = y[i]+1;

    }

    sort(diffXs,diffXs + diffNum);

    diffNum = unique(diffXs,diffXs+diffNum) - diffXs;

    FLC(add,0);
    FLC(cover,0);
    FLC(prefixSum,0);

    for(int i = 0;i<N;i++){
        int posX = lower_bound(diffXs,diffXs + diffNum,x[i])-diffXs;
        int posY = upper_bound(diffXs,diffXs + diffNum,y[i])-diffXs;
        add[posX]++;
        add[posY]--;
    }

    LL sum = 0;

    for(int i = 0;i<diffNum;i++){
        sum += add[i];
        cover[i] = sum;
    }

    int totalLen = 0;

    for(int i = 0;i<diffNum;i++){
        
        if(i) prefixSum[i] = prefixSum[i-1];

        if(cover[i]==1){
            prefixSum[i] += (diffXs[i+1]-diffXs[i]);
        }
        if(cover[i] > 0){
            totalLen += (diffXs[i+1] - diffXs[i]);
        }
    }

    
    LL ans = totalLen;

    for(int i = 0;i<N;i++){

        int posX = lower_bound(diffXs,diffXs+diffNum,x[i]) - diffXs;
        
        int posY = upper_bound(diffXs,diffXs+diffNum,y[i]) - diffXs;

        LL first = prefixSum[posY-1];

        LL second = 0;

        if(posX > 0){
            second = prefixSum[posX-1];
        }

        ans = min(ans,totalLen - (first - second ) );

    }

    return ans;

}


int main() {

        
    int t;
    
    int cas;

    cas = 0;

    scanf("%d",&t);

    while(t--){
        
        cas++ ;

        printf("Case #%d: ",cas );

        LL ans = solve();

        cout<<ans<<endl;

    }
    return 0;
}








