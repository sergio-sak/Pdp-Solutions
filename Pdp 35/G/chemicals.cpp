#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, K, temp, left = 0, right = 0, complement, res = 0;
vll chemicals;
std::unordered_map<ll, ll> hmap;

int main()
{
    #ifdef CONTEST
        freopen("chemicals.in", "r", stdin);
        freopen("chemicals.out", "w", stdout);
    #else
        freopen("testcases/chemicals.in1", "r", stdin);
    #endif

    scanf("%lld %lld", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%lld", &temp);
        chemicals.push_back(temp%K);
    }

    while(left<=right && right < N) {
        complement = K - chemicals[right];
        if(complement == K) complement = 0;
        if(hmap.count(complement) && hmap[complement] > 0){
            while(hmap[complement] != 0){
                hmap[chemicals[left]]--;
                left++;
            }
        }
        hmap[chemicals[right]]++;
        right++;
        res = std::max(res, right-left);
        // std::cout << left << " " << right << " " << res << std::endl;
    }
    printf("%lld\n", res);
    return 0;
}