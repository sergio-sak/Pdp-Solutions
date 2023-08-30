#include <bits/stdc++.h>

long N, temp;
std::vector<long> number, res;

int main()
{
    #ifdef CONTEST
        freopen("twosqr.in", "r", stdin);
        freopen("twosqr.out", "w", stdout);
    #else
        freopen("twosqr.in1", "r", stdin);
    #endif
    scanf("%ld", &N);
    for(int i = 0; i < N; ++i){
        scanf("%ld", &temp);
        number.push_back(temp);
        res.push_back(0);
        for(int j = 0; j <= sqrt(number[i]); ++j){
            for(int x = 0; x <= sqrt(number[i]); ++x){
                if(x*x + j*j==number[i]&&x<=j){
                    res[i]++;
                    //std::cout<<"Number: "<<number[i]<<" x: "<<x<<" j: "<<j<<" x^2 + j^2= "<<x*x+j*j<<std::endl;
                }
            }
        }
        printf("%ld\n", res[i]);
    }
    return 0;
}
