#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, K, dif, max = -1, sum;
int nums[(size_t)(1e6+6)];
std::unordered_map<int, int> hmap;

int main()
{
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    int left = 0, right = 0;
    while(right < N){
        sum += nums[right];
        dif += !(hmap[nums[right++]]++);
        while(dif > K){
            sum -= nums[left];
            dif -= !(--hmap[nums[left++]]);
        }
        max = std::max(max, sum);
    }
    printf("%d\n", max);
    return 0;
}
