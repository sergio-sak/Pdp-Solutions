#include <bits/stdc++.h>

long N, M, temp, result;

int main()
{
    #ifndef CONTEST
        freopen("domes.in1", "r", stdin);
    #endif
    
    #ifdef CONTEST
        freopen("domes.in", "r", stdin);
        freopen("domes.out", "w", stdout);
    #endif
    scanf("%ld %ld", &N, &M);
    std::vector<long> domes(N+1, 0);
    for(int i = 1; i <= M*2; ++i){
        scanf("%ld", &temp);
        domes[temp]++;
    }
    for(int i = 1; i <= N; ++i){
        if(domes[i]<2)
            result++;
    }
    printf("%ld", result);
    return 0;
}