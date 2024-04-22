#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 1000005
#define EPS 1e-9

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pllll;
typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::unordered_map<int , int> mii;
typedef std::unordered_map<ll , ll> mllll;
typedef std::unordered_map<char , int> mci;
typedef std::unordered_map<char , ll> mcll;

ll N, K, sum1, sum2, maxsum, num, ans;
vll prefix, nums;

int main()
{
    #ifdef CONTEST
        freopen("scrabble1d.in", "r", stdin);
        freopen("scrabble1d.out", "w", stdout);
    #else
        freopen("scrabble1d.in", "r", stdin);
    #endif
    scanf("%lld %lld", &N, &K);

    prefix.pb(0);
    FOR(i, 0, N) {
        scanf("%lld", &num);
        sum1 += num;        
        prefix.pb(sum1);
    }

    sum1 = sum2 = 0;

    FORD(i, N - 2 * K + 1, 1) {
        sum1 = prefix[i + K - 1] - prefix[i-1];
        sum2 = prefix[i + 2 * K - 1] - prefix[i + K - 1];
        maxsum = std::max(maxsum, sum2);
        ans = std::max(ans, sum1+maxsum);
    }

    printf("%lld\n", ans);
    return 0;
}
