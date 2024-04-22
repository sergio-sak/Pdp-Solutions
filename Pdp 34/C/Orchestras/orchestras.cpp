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

ll N, K, D = INT64_MIN, num, cur_max = INT64_MIN, cur_min = INT64_MAX;

int main()
{
    #ifdef CONTEST
        freopen("orchestras.in", "r", stdin);
        freopen("orchestras.out", "w", stdout);
    #else
        freopen("orchestras.in", "r", stdin);
    #endif
    
    scanf("%lld %lld", &N, &K);
    std::vector<std::vector<ll>> orchestras;
    orchestras.resize(K+1, std::vector<ll>(N+1));

    FOR(i, 0, K) {
        FOR(j, 0, N) {
            scanf("%lld", &num);
            orchestras[i][j] = num;
        }
    }

    //sort
    FOR(i, 0, K) {
        std::sort(orchestras[i].rbegin(), orchestras[i].rend());
    }

    //solve
    FOR(outer, 0, N){
        FOR(inner, 0, K) {
            cur_max = std::max(cur_max, orchestras[inner][outer]);
            cur_min = std::min(cur_min, orchestras[inner][outer]);
        }
        D = std::max(D, cur_max - cur_min);
        cur_max = INT64_MIN;
        cur_min = INT64_MAX;
    }
    
    // print
    // for(auto outer : orchestras) {
    //     for(auto inner : outer) {
    //         std::cout<<inner<<" ";
    //     }
    //     std::cout<<std::endl;
    // }

    printf("%lld\n", D);
    return 0;
}
