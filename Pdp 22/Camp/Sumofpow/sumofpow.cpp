#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, count, cur2, cur3, cur5, res;
vll pow2, pow3, pow5;
std::set<ll> s;

ll fast_power(ll base, ll power) {
    ll result = 1;
    while(power > 0) {
        if(power&1)
            result = result*base;
        base = base * base;
        power >>= 1;
    }
    return result;
}

int main()
{
    #ifdef CONTEST
        freopen("sumofpow.in", "r", stdin);
        freopen("sumofpow.out", "w", stdout);
    #else
        freopen("sumofpow.in", "r", stdin);
    #endif
    scanf("%lld", &N);
    
    while(cur2 <= N-2){
        cur2 = 1<<count;
        cur3 = fast_power(3, count);
        cur5 = fast_power(5, count);

        if(cur2 <= N-2){
            pow2.push_back(cur2);
        }
        if(cur3 <= N-2){
            pow3.push_back(cur3);
        }
        if(cur5 <= N-2){
            pow5.push_back(cur5);
        } 
        count++;
    }

    for(int i = 0; i < pow2.size(); ++i) {
        for(int j = 0; j < pow3.size(); ++j) {
            for(int k = 0; k < pow5.size(); ++k) {
                // std::cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<" sum: "<<pow2[i] + pow3[j] + pow5[k]<<std::endl;
                if(pow2[i] + pow3[j] + pow5[k] <= N)
                    s.insert(pow2[i] + pow3[j] + pow5[k]);
            }
        }
    }
    res = s.size();
    printf("%lld\n", res);
    return 0;
}
