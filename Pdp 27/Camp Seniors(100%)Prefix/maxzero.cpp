#include <bits/stdc++.h>

std::unordered_map<int, std::pair<int, int>> hmap;
std::vector<long> prefix;
int N, res = 0, temp = 0;

int main()
{
    #ifdef CONTEST
        freopen("maxzero.in", "r", stdin);
        freopen("maxzero.out", "w", stdout);
    #else
        freopen("maxzero.in4", "r", stdin);
    #endif
    
    scanf("%d", &N);
    prefix.push_back(0);
    hmap[0].first=0;
    
    for(int i = 1, prefix_cur = 0; i <= N; ++i){
        scanf("%d", &temp);   
        prefix_cur += temp;
        prefix.push_back(prefix_cur);
        if(hmap.find(prefix_cur)==hmap.end())
            hmap[prefix_cur].first=i;
        hmap[prefix_cur].second=i;
    }

    if(hmap.find(0)!=hmap.end()){
        res = hmap[0].first;
    }
    for(int i = 1; i <= N; ++i){
        if(hmap.find(prefix[i])!=hmap.end()){
            res = std::max(res, hmap[prefix[i]].second - hmap[prefix[i]].first);
        }
    }
    printf("%d\n", res);
    return 0;
}