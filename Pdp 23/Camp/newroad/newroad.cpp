#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <bit>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <inttypes.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")

#define EPS 1e-9
#define PI acos(-1)
#define MAXN 10'005
#define MOD 1'000'000'007
#define INF 1'000'000'000'000

#define ll int64_t
#define int int32_t
#define short int16_t

#define si(n) scanf("%" PRId32, &n);
#define sl(n) scanf("%ld", &n);
#define sc(n) scanf("%c", &n);
#define sf(n) scanf("%f", &n);
#define slf(n) scanf("%lf", &n);

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dbg(x) std::cerr << #x << ": " << x << std::endl;

typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<std::vector<int>> dvi;
typedef std::vector<std::vector<ll>> dvll;
typedef std::unordered_map<int , int> mi;
typedef std::unordered_map<ll , ll> mll;

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a%b);}
ll lcm(ll a, ll b) {return a/gcd(a, b) * b;}

bool vis[MAXN];
std::vector<pll> adjFwd[MAXN], adjRev[MAXN];
ll N, M, K, start, end, distFwd[MAXN], distRev[MAXN];

void dijkstra(ll s, std::vector<pll> adj[], ll* dist) {
    for(int i = 1; i <= N; ++i) {
        dist[i] = INF;
        vis[i] = false;
    }
    std::priority_queue<pll> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        ll u = pq.top().se; pq.pop();
        if(vis[u]) continue;
        vis[u] = true;

        for(auto [v, w] : adj[u]) {
            if(vis[v]) continue;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

signed main()
{
    // freopen("newroad.in", "r", stdin);
    // freopen("newroad.out", "w", stdout);
 
    sl(N); sl(M); sl(K); sl(start); sl(end);

    while(M--) {
        ll u, v, w;
        sl(u); sl(v); sl(w);
        adjFwd[u].pb({v, w});
        adjRev[v].pb({u, w});
    }

    dijkstra(start, adjFwd, distFwd);
    dijkstra(end, adjRev, distRev);

    ll ans = distFwd[end];
    while(K--) {
        ll u, v, w;
        sl(u); sl(v); sl(w);

        if(distFwd[u] == INF || distRev[v] == INF) continue;
        ll dist = distFwd[u] + distRev[v] + w;
        ans = std::min(ans, dist);
    }

    printf("%ld\n", ans);
    return 0;
}
