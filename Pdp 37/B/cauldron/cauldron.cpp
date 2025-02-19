#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

std::vector<long long> vases;
long long subtest, N, K, c;

signed main()
{
    freopen("cauldron.in", "r", stdin);
    scanf("%lld\n%lld%lld%lld", &subtest, &N, &K, &c);
    
    vases.resize(N+1);
    for(int i = 1; i <= N; ++i) {scanf("%lld", &vases[i]);}
    
    std::sort(vases.begin(), vases.end());
    
    for(int i = 1; i <= N; ++i) {
        vases[i] += vases[i-1];
    }
    
    long long left = 1, right = 1, max = 0;
    for(left; left <= N; ++left) {
        while(right <= N && vases[right+1] - vases[left-1] <= K) {
            right++;
        }
        max = std::max(max, K + c * (right - left + 1));
    }
    
    freopen("cauldron.out", "w", stdout);
    printf("%lld\n", max);
    return 0;
}