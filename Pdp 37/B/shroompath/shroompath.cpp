#include <iostream>
#include <algorithm>
#include <utility>
#define ll long long

ll subtest, S, X, Y, ceilX, ceilY;
long long MOD = 1000000007;

ll expo(ll x, ll y, ll p = MOD){
    ll answer = 1;
    for(int i=0;i<y;i++){
        answer = (answer*x)%p;
    }
    return answer%p;
}

signed main()
{ 
    freopen("shroompath.in", "r", stdin);
    scanf("%lld \n %lld %lld %lld", &subtest, &S, &X, &Y);
    
    if(X!=0) ceilX = (S/X) + ((S%X) != 0);
    if(Y!=0) ceilY = (S/Y) + ((S%Y) != 0);
    
    
    freopen("shroompath.out", "w", stdout);
    
    if(X == 0) printf("%lld\n", (2 + (((ceilY-2)*(expo(2, ceilY))%MOD)%MOD + (expo(2, ceilY - 1) * ceilY)%MOD)%MOD + 1)%MOD);
    else if(Y == 0  || subtest == 3) printf("%lld\n", (2 + ((ceilX/2 - 1) * expo(2, ceilX/2 + 1))%MOD + ceilX)%MOD);
    else printf("%lld\n", std::min((2 + ((ceilX/2 - 1) * expo(2, ceilX/2 + 1))%MOD + ceilX)%MOD, (2 + (((ceilY-2)*(expo(2, ceilY))%MOD)%MOD + (expo(2, ceilY - 1) * ceilY)%MOD)%MOD + 1)%MOD));
    return 0;
}