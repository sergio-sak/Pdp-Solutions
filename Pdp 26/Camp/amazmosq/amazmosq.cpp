#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll S, K, N, total;
vll sums(50000005);

int main()
{
    #ifdef CONTEST
        freopen("amazmosq.in", "r", stdin);
        freopen("amazmosq.out", "w", stdout);
    #else
        freopen("amazmosq.in2", "r", stdin);
    #endif
    scanf("%lld %lld %lld", &S, &K, &N);

    sums[0] = S;
    for(int i = 1; i <= N; ++i) {
        sums[i] = (sums[i-1] * K) % 20140409;
    }

    for(int i = 0; i <= N; ++i) {
        total += sums[i];
    }

    printf("%lld\n", total%20140409);
    return 0;
}
