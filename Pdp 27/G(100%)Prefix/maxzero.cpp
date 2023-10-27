#include <bits/stdc++.h>

std::unordered_map<long long, std::vector<long long>> hmap;
std::vector<long long> prefix;
long long N, res = 0, temp = 0;

int main()
{
    #ifdef CONTEST
        freopen("maxzero.in", "r", stdin);
        freopen("maxzero.out", "w", stdout);
    #else
        freopen("maxzero.in", "r", stdin);
    #endif
    
    scanf("%ld", &N);
    for(long long i = 0, prefix_cur = 0; i < N; ++i){
        scanf("%ld", &temp);   
        prefix_cur += temp;
        prefix.push_back(prefix_cur);
        hmap[prefix_cur].push_back(i);
    }
    if(hmap.find(0)!=hmap.end()){
        res = hmap[0].back()+1;
    }
    for(long long i = 0; i < N; ++i){
        if(hmap[prefix[i]].size()>1){
            res = std::max(res, hmap[prefix[i]].back() - hmap[prefix[i]][0]);
        }
    }
    printf("%ld\n", res);
    return 0;
}