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
typedef std::map<ll , ll> mllll;
typedef std::unordered_map<char , int> mci;
typedef std::unordered_map<char , ll> mcll;

bool comp(pllll p1, pllll p2) {
    return p1.se > p2.se;
}

std::vector<pllll> servers_for_sort;
ll N, M, K, query, numquery;
mllll servers;

int main()
{
    #ifdef CONTEST
        freopen("servers.in", "r", stdin);
        freopen("servers.out", "w", stdout);
    #else
        freopen("servers.in", "r", stdin);
    #endif
    scanf("%lld %lld %lld", &M, &N, &K);
     
    FOR(i, 0, N*M) {
        scanf("%lld %lld", &query, &numquery);
        servers[query] += numquery;
    }

    for(auto server : servers) {
        servers_for_sort.pb(server);
    }

    std::sort(servers_for_sort.begin(), servers_for_sort.end(), comp);
    
    FOR(i, 0, K) {
        printf("%lld %lld\n", servers_for_sort[i].fi, servers_for_sort[i].se);
    }
    return 0;
}
