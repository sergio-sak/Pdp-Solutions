#include <bits/stdc++.h>

long N, M, K = 0, X = 1000001, Y = 0, temp;
std::vector<long> aris;

int main()
{
    #ifndef CONTEST
        freopen("aris.in1", "r", stdin);
    #endif
    
    #ifdef CONTEST
        freopen("aris.in", "r", stdin);
        freopen("aris.out", "w", stdout);
    #endif
    scanf("%ld %ld", &N, &M);
    aris.resize(M+1, 0);
    for(int i = 1; i <= N; ++i){
        scanf("%ld", &temp);
        aris[temp]++;
    }
    for(int i = 1; i <= M; ++i){
        if(aris[i]!=0)
            K++;
        if(aris[i]<X && aris[i] != 0)
            X = aris[i];
        if(aris[i]>Y)
         Y = aris[i];
    }
    printf("%ld %ld %ld\n", K, X, Y);
    return 0;
}