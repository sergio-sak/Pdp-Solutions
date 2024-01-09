#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, temp;
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
    
    return 0;
}
