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
#include <inttypes.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")

#define EPS 1e-9
#define PI acos(-1)
#define MAXN 1000005
#define MOD 1000000007
#define INF 1'000'000'000'000

#define ll int_fast64_t
// #define int int_fast32_t
#define short int_fast16_t

#define si(n) scanf("%d", &n);
#define sl(n) scanf("%" PRIdFAST64, &n);
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
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> dvi;
typedef std::vector<std::vector<ll>> dvll;
typedef std::unordered_map<int , int> mi;
typedef std::unordered_map<ll , ll> mll;

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a%b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a, b);}

int log2_floor(unsigned int i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int N, ans = -1;
int st[25][1000005];
std::stack<int> mst;

void init() {
    for (int i = 1; i <= log2_floor(N)+1; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

signed main()
{
    // freopen("solar.in", "r", stdin);
    // freopen("solar.out", "w", stdout);
    
    si(N);
    for(int i = 0; i < N; ++i) {
        si(st[0][i]);
    } init();

    for(int i = 0; i < N; ++i) {
        while(mst.size() && mst.top() < st[0][i]) {
            mst.pop();
        } mst.push(st[0][i]);

        if(mst.size() == 1) {
            int lg = log2_floor(N - i + 1);
            int minimum = std::min(st[lg][i+1], st[lg][N - (1 << lg)]);
            if(st[0][i] < minimum) ans = st[0][i];
        }
    }

    if(ans == -1) printf("NOT FOUND\n");
    else printf("%d", ans);
    return 0;
}
