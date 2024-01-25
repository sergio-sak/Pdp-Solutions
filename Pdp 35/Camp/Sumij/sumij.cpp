#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll T, N, s, max_dif;
vll sum, nums;
std::unordered_map<ll, ll> hmap;
pl res;

int main()
{
    #ifdef CONTEST
        freopen("sumij.in", "r", stdin);
        freopen("sumij.out", "w", stdout);
    #else
        freopen("sumij.in", "r", stdin);
    #endif
    scanf("%lld", &T);
    for(int j = 0; j < T; ++j)
    {
        sum.clear();
        s = 0;
        hmap.clear();
        res = {-1, -1};
        max_dif = 0;
        scanf("%lld", &N);
        sum.push_back(0);
        for(int i = 1; i <= N; ++i){
            ll temp;
            scanf("%lld", &temp);
            s+=temp;
            sum.push_back(s);
            hmap[s-i] = i;
        }

        for(int i = 1; i <= N; ++i){
            if(hmap.count(sum[i-1] + i)){
                if(max_dif < hmap[sum[i-1] + i] - i){
                    max_dif = hmap[sum[i-1] + i] - i;
                    res = {i, hmap[sum[i-1] + i]};
                }
            }
        }
        if(res.first == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld %lld\n", res.first, res.second);
    }
    return 0;
}
