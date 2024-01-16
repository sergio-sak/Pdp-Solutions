#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, temp, max1 = -1, max2 = -1, max3 = -1;
vll ms1, ms2, ms3;

int main()
{
    #ifdef CONTEST
        freopen("max3sum.in", "r", stdin);
        freopen("max3sum.out", "w", stdout);
    #else
        freopen("testcases/max3sum.in1", "r", stdin);
    #endif
    
    scanf("%lld", &N);

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < N; ++j){
            scanf("%lld", &temp);
            if(i == 0)
                ms1.push_back(temp);
            else if(i == 1)
                ms2.push_back(temp);
            else
                ms3.push_back(temp);
        }
    }
    
    for(int i = 0; i < N-2; ++i){ //N-2 gia na mhn vgazei seg fault
        max1 = std::max(max1, ms1[i]);
        max2 = std::max(max2, max1 + ms2[i+1]);
        max3 = std::max(max3, max2 + ms3[i+2]);   
        // std::cout << max1 << " " << max2 << " " << max3 << std::endl;
    }
    printf ("%lld\n", max3);
    return 0;
}
