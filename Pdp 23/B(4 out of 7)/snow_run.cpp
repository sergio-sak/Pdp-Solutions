#include <bits/stdc++.h>

long long N, cur, compare;
std::unordered_map<long long, long long> res;

int main()
{
    #ifdef CONTEST
        freopen("snow_run.in", "r", stdin);
        freopen("snow_run.out", "w", stdout);
    #else
        freopen("snow_run.in5", "r", stdin);
    #endif
    scanf("%ld", &N);
    for(long long i = 1; i <= N; ++i){
        scanf("%ld", &cur);
        res[i] = cur;
    }
    for(long long i = N; i >= 1; --i){
        compare = res[i];
        for(long long j = i; j >= 1; --j){
            if(compare <= res[j] && i != j){
                res[j]++;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        printf("%ld\n", res[i]);
    }
    return 0; //(4/7)
}
//std::cout<<"I: "<<i<<"\nCur: "<<cur<<"\n";
// std::cout<<"Compare: "<<compare<<" res[j]: "<<res[j]<<" J: "<<j<<std::endl;
//std::cout<<"Compare: "<<compare<<"\n";