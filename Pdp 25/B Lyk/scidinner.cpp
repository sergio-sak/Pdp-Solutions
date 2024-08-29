#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <inttypes.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")

#define EPS 1e-9
#define PI acos(-1)
#define MAXN 1000005
#define MOD 1'000'000'007
#define INF 1'000'000'000'000

#define ll int64_t
// #define int int_fast32_t
#define short int_fast16_t

#define si(n) scanf("%d", &n);
#define sl(n) scanf("%d", &n);
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
typedef std::vector<int> vll;
typedef std::vector<std::vector<int>> dvi;
typedef std::vector<std::vector<ll>> dvll;
typedef std::unordered_map<int , int> mi;
typedef std::unordered_map<ll , ll> mll;

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a%b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a, b);}

vi adj[MAXN];
bool child[MAXN];
int N, M, max_dist, dist[MAXN];

void bfs(int x) {
    std::stack<int> q;
    dist[x] = 1;
    q.push(x);

    while(!q.empty()) {
        int u = q.top(); q.pop();

        for(int v : adj[u]) {
            dist[v] = dist[u] + 1;
            max_dist = std::max(max_dist, dist[v]);
            q.push(v);
        }
    }
}

void dfs_help() {
    for(int i = 1; i <= N; ++i) {
        if(!child[i]) {
            bfs(i);
        }
    }
}
signed main()
{
    #ifdef CONTEST
        freopen("scidinner.in", "r", stdin);
        freopen("scidinner.out", "w", stdout);
    #endif
    
    sl(N); sl(M);
    for(int i = 0; i < M; ++i) {
        int u, v;
        sl(u); sl(v);
        adj[u].pb(v);
        child[v] = true;
    } dfs_help();

    printf("%ld", max_dist);
    return 0;
}
