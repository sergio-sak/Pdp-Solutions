#include <bits/stdc++.h>

std::unordered_map<long, std::vector<long>> hmap;
std::vector<long> nums;
long N;

int main()
{
    #ifdef CONTEST
        freopen("landfight.in", "r", stdin);
        freopen("landfight.out", "w", stdout);
    #else
        freopen("landfight.in", "r", stdin);
    #endif
    scanf("%ld", &N);
    nums.resize(N+3);
    for(int i = 1; i <= N; ++i){
        scanf("%ld", &nums[i]);
    }
    //Suffix Sum calculate
    hmap[0].push_back(N+1);
    for(long suffix = 0, i = N; i > 0; --i){
        suffix += nums[i];
        hmap[suffix].push_back(i);
    }
    long res = N;
    for(long prefix = 0, i = 0; i <= N; ++i){
        prefix+=nums[i];
        if(hmap.find(prefix) == hmap.end())
            continue;
        std::vector<long>& hmap_ref = hmap[prefix];
        while(!hmap_ref.empty() && hmap_ref.back() <= i)
            hmap_ref.pop_back();
        if(!hmap_ref.empty()){
            res = std::min(res, hmap_ref.back() - i - 1);
        }
    }
    printf("%ld\n", res);
    return 0;
}