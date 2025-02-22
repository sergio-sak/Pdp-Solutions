#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
// #include <bit>
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
#define sl(n) scanf("%llu", &n);
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

double A;
std::vector<unsigned long long> group;
unsigned long long N, B, ans;

unsigned long long check(unsigned long long x) {
    unsigned long long sum = 0;
    for(unsigned long long i = 0; i < N; ++i) {
        if(x < 10) x = 0;
        sum += group[i] * x;
        x = (unsigned long long)x*A;
    }

    return sum;
}

signed main()
{
    freopen("coupon.in", "r", stdin);
    freopen("coupon.out", "w", stdout);

    sl(N); slf(A); sl(B); group.resize(N);
    for(unsigned long long & v:group) sl(v);

    unsigned long long low = 0, high = B/group[0] + 10, mid;
    while(low < high) {
        mid = (low + high + 1)/2; // Isodynamo me std::Ceil()
        ans = check(mid);
        
        if(ans <= B) low = mid;
        else high = mid-1;
    }

    printf("%llu\n", check(low));
    for(unsigned long long i = 0; i < N; ++i) {
        if(low >= 10) {
            printf("%llu\n", low);
            low *= A;
        } else printf("0\n");
    }
    return 0;
}
