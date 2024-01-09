#include <bits/stdc++.h>

long long N, M, prefix = 0, temp, res = 0;
std::vector<long long> sum;
std::unordered_map<long long, std::vector<long long>> hmap;

int main()
{
    #ifdef CONTEST
        freopen("mulsum.in", "r", stdin);
        freopen("mulsum.out", "w", stdout);
    #else
        freopen("testcases/mulsum.in4", "r", stdin);
    #endif
    scanf("%lld %lld", &N, &M);
    sum.push_back(0);
    hmap[0].push_back(0);
    for(int i = 1; i <= N; ++i){
        scanf("%lld", &temp);       
        prefix += temp;
        sum.push_back(prefix);
        hmap[std::abs(prefix % M)].push_back(i);
    }
    for(int i = 0; i < N; ++i){
        while(hmap[sum[i]%M].size()>1){
            res = std::max(res, sum[hmap[sum[i]%M].back()] - sum[i]);
            hmap[sum[i]%M].pop_back();
        }
    }
    printf("%lld", res);
    return 0;
}
