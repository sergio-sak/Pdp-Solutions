#include <bits/stdc++.h>

long long N, B, low = 10, mid, high, C_var, max_B;
float A; 
std::vector<long long> C(1), result;

long long calculate_B(long long temp_mid, float temp_A, std::vector<long long> temp_C, long long temp_N){
    long long temp_B = 0;
    for(int i = 1; i <= temp_N; ++i){
        temp_B += temp_mid * temp_C[i];
        temp_mid *= temp_A;
        if (temp_mid < 10){
            temp_mid /= temp_A;
            break;
        }
    }
    return temp_B;
}

int main()
{
    #ifndef CONTEST
        freopen("coupon.in1", "r", stdin);
    #endif
    #ifdef CONTEST
        freopen("coupon.in", "r", stdin);
        freopen("coupon.out", "w", stdout);
    #endif
    scanf("%lld %f %lld", &N, &A, &B);
    for(int i = 1; i <= N; ++i){
        scanf("%lld", &C_var);
        C.push_back(C_var);
    }
    high = B / C[1];
    while(low <= high){
        if (max_B <= B)
            low = mid + 1;
        else
            high = mid - 1;
        mid = (low + high) / 2;
        max_B = calculate_B(mid, A, C, N);
    }
    std::cout<<max_B<<std::endl;
    for(int i = 1; i <= N; ++i){
        if(mid >= 10){
            printf("%lld\n", mid);
            mid *= A;
        }
        else
            printf("%d\n", 0);
    }
    return 0;
}