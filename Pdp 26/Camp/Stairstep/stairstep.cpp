#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

vi nums(1000005), dp(1000005);
int N;

int main()
{
    #ifdef CONTEST
        freopen("stairstep.in", "r", stdin);
        freopen("stairstep.out", "w", stdout);
    #else
        freopen("stairstep.in2", "r", stdin);
    #endif
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &nums[i]);
    }
    dp[0] = 0;
    dp[1] = nums[1];
    for(int i = 2; i <= N+1; ++i){
        dp[i] = std::max(dp[i-1], dp[i-2]) + nums[i];
    }
    printf("%d\n", dp[N+1]);
    return 0;
}
