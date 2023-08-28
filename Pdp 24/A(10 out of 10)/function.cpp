#include <bits/stdc++.h>

std::vector<bool> vec;
int N, M;

int main()
{
    #ifdef CONTEST
        freopen("function.out", "w", stdout);
    #endif
    freopen("function.in", "r", stdin);
    scanf("%d %d", &N, &M);
    if(N > M)
        std::swap(N, M);
    vec.resize(M+1, true);
    for(int i = 2; i*i <= M; ++i){
        if(vec[i]){
            for(int j = i*i; j <= M; j+=i){
                vec[j] = false;
            }
        }
        
    }
    for(int i = N+1; i < M; ++i){
        if(vec[i]){
            if(i != 2)
                std::cout<<i<<" ";
        }
    }
    
}