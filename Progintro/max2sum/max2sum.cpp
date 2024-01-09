#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, temp, max1 = 0, max2 = 0;
vll max2sum;

int main()
{
    #ifdef CONTEST
        freopen("max2sum.in", "r", stdin);
        freopen("max2sum.out", "w", stdout);
    #else
        freopen("max2sum.in", "r", stdin);
    #endif
    
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &temp);
        max1 = std::max(max1, temp+i);
        max2 = std::max(max2, temp-i);  
    }
    printf("%lld\n", max1+max2);
    return 0;
}
