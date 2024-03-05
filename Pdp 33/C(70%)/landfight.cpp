#include <bits/stdc++.h>

long long min = 1e6+5, N;
std::vector<long long> prices;
double

int main()
{
    #ifdef CONTEST
        freopen("profit.in", "r", stdin);
        freopen("profit.out", "w", stdout);
    #else
        freopen("profit.in1", "r", stdin);
    #endif
    scanf("%lld", &N);
    prices.resize(N+1, 0);
    for(int i = 0; i < N; ++i){
        scanf("%lld", &prices[i]);
    }
    for(int i = 0; i < N; ++i){
        min = std::min(min, prices[i]);
       
    }
    return 0;
}
