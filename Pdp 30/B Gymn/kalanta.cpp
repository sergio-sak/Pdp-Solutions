#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

vi nums((size_t)(2*1e6+6));
ll N, sum = 0, temp, min = 1e9, right = 1, cur = 0;

int main()
{
    #ifdef CONTEST
        freopen("kalanta.in", "r", stdin);
        freopen("kalanta.out", "w", stdout);
    #else
        freopen("kalanta.in2", "r", stdin);
    #endif
    scanf("%d", &N);

    for(int i = 1; i <= N; ++i){
        scanf("%d", &nums[i]);
        nums[i+N] = nums[i];
        sum += nums[i];
    }

    for(int left = 1; left <= N; ++left) {
        cur -= nums[left-1];
        while(right < left + N && cur + nums[right] <= sum/2){
            cur += nums[right];
            right++;
        }
        temp = sum - cur;
        min = std::min(min, std::abs(cur - temp));
    }

    printf("%d\n", min);
    return 0;
}
