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
#define MAXN 1'000'005
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

ll *goodlong;
ll N, K, maxWindow, sum, r = 1;

signed main()
{
    freopen("goodlong.in", "r", stdin);
    freopen("goodlong.out", "w", stdout);

    sl(N); sl(K);
    goodlong = new ll[N+1];
    goodlong[0] = 0;

    for(int i = 1; i <= N; ++i) {
        sl(goodlong[i]);
        goodlong[i] += goodlong[i-1];
    }

    for(ll l = 1; l <= N && r <= N; ++l) {
        for(ll r = l; r <= N; ++r) {
        // r = std::max(l, r);
        // while(r<=N && goodlong[r] - goodlong[l-1] >= 0){
            if(goodlong[r] - goodlong[l-1] >= K * (r - l + 1))
                maxWindow = std::max(maxWindow, r-l+1);
            // r++;
        }
    }

    printf("%ld\n", maxWindow);
    delete[] goodlong;
    return 0;
}
