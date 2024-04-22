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

ll N, K, chemical, ans, left, right, complement;
vll chemicals;
mllll oxidations;

int main()
{
    #ifdef CONTEST
        freopen("chemicals.in", "r", stdin);
        freopen("chemicals.out", "w", stdout);
    #else
        freopen("testcases/chemicals.in1", "r", stdin);
    #endif
    scanf("%lld %lld", &N, &K);

    FOR(i, 0, N) {
        scanf("%lld", &chemical);
        chemicals.pb(chemical % K);
    }

    while(left <= right && right < N) {
        complement = K - chemicals[right];
        if(complement == K) complement = 0;

        if(oxidations.find(complement) != oxidations.end()) {
            while(oxidations[complement] != 0) {
                oxidations[chemicals[left]]--;
                left++;
            }
        }

        oxidations[chemicals[right]]++;
        right++;
        ans = std::max(ans, right - left);
    }

    printf("%lld\n", ans);
    return 0;
}
