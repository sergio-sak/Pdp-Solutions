#include <bits/stdc++.h>

long L; 
double spins, temp;
std::vector<long> K(1);
std::vector<double> M(1, 1), spinsV(1);

int main()
{
    #ifndef CONTEST
        freopen("astrolavos.in2", "r", stdin);
    #endif

    #ifdef CONTEST
        freopen("astrolavos.in", "r", stdin);
        freopen("astrolavos.out", "w", stdout);
    #endif
    scanf("%ld", &L);
    for(int i = 1; i <= L; ++i){
        scanf("%lf", &temp);
        M.push_back(temp);
    }
    scanf("%lf", &spins);
    for(int i = 1; i <= 5; ++i){
        scanf("%lf", &temp);
        K.push_back(temp);
    }
    
    for(int i = 2; i <= L; ++i){
        spinsV[i] = M[i-1] * spins / M[i];
        spins = spinsV[i];
    }

    for(int i = 1; i <= 5; ++i){
        printf("%.3lf ", static_cast<double>(spinsV[K[i]]));
    }
    printf("\n");
    return 0;
}
