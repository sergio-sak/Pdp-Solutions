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
#include <time.h>
#include <random>
#include <iomanip>
#include <inttypes.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace __gnu_pbds;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,Ofast")

#define EPS 1e-9
#define PI acos(-1)
#define MAXN 1'000'005
#define MOD 1'000'000'007
#define INF 1'000'000'000'000

#define ll int64_t
#define int int32_t
#define short int16_t

#define si(n) scanf("%d", &n);
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

int N, K, ans;
int *profit, *maxBefore;

signed main()
{
    si(N); si(K);

    profit = new int[N+1];
    maxBefore = new int[N+1];

    for(int i = 1; i <= N; ++i) {
        si(profit[i]);
        profit[i] += profit[i-1];
        if(i - K >= 0) maxBefore[i] = std::max(maxBefore[i-1], profit[i] - profit[i-K]);
    }

    for(int i = 2*K; i <= N; ++i) {
        ans = std::max(ans, profit[i]-profit[i-K] + maxBefore[i - K]);
    }

    printf("%d\n", ans);
    return 0;
}
