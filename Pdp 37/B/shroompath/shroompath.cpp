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
    else if(Y == 0  || subtest == 3) printf("%lld\n", ((2 + ((ceilX/2 - 1) * expo(2, ceilX/2 + 1))%MOD + ceilX)%MOD)%MOD);
    else printf("%lld\n", std::min(((2 + ((ceilX/2 - 1) * expo(2, ceilX/2 + 1))%MOD + ceilX)%MOD)%MOD, (2 + (((ceilY-2)*(expo(2, ceilY))%MOD)%MOD + (expo(2, ceilY - 1) * ceilY)%MOD)%MOD + 1)%MOD));
    return 0;
}




#include <iostream>
#include <algorithm>
#include <utility>
#define ll long long

ll subtest, S, X, Y, ceilX, ceilY;
long long MOD = 1000000007;

ll expo(ll base, ll expon, ll mod = MOD){
    ll res = 1;
    while(expon > 0) {
        if(expon % 2 == 1) res = (res*base) % mod;
        base = (base*base) % mod;
        expon /= 2;
    }
    return res%mod;
}

long long computeX(long long S, long long X) {
    long long ceilSX = (S + X - 1) / X;
    long long floorHalf = ceilSX / 2;
    
    long long powerTerm = expo(2, floorHalf + 1, MOD);
    long long term = ((floorHalf - 1) * powerTerm ) % MOD;
    
    long long result = (2 + term + ceilSX) % MOD;
    
    return (result + MOD) % MOD;
}

long long computeY(long long S, long long Y) {
    long long ceilSY = (S + Y - 1)/Y;
    long long powerTerm = expo(2, ceilSY, MOD);
    long long term1 = ((ceilSY - 2) * powerTerm) % MOD;
    long long term2 = (powerTerm/2 * ceilSY)%MOD;
    long long result = 3 + term1 + term2;
    return (result + MOD) % MOD;
}

signed main()
{ 
    freopen("shroompath.in", "r", stdin);
    scanf("%lld \n %lld %lld %lld", &subtest, &S, &X, &Y);

    freopen("shroompath.out", "w", stdout);
    if(X == 0) printf("%lld\n", computeY(S, Y));
    if(Y == 0) printf("%lld\n", computeX(S, X));
    else printf("%lld\n", std::min(computeX(S, X), computeY(S, Y)));
    return 0;
}