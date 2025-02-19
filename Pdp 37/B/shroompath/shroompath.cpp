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
#include <time.h>
#include <random>
// #include <iomanip>
// #include <inttypes.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 

// using namespace __gnu_pbds;

// template <class T>
// using Tree = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("O3,Ofast")

#define EPS 1e-9
#define PI acos(-1)
#define MAXN 1'000'005
#define MOD 1'000'000'007
#define INF 1'000'000'000'000

#define si(n) scanf("%d", &n);
#define sl(n) scanf("%lld", &n);
#define sc(n) scanf("%c", &n);
#define sf(n) scanf("%f", &n);
#define slf(n) scanf("%lf", &n);

#define fi first
#define se second
#define ll long long
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

ll subtest, S, X, Y;

ll expo(ll x, ll y, ll p = MOD){
    ll answer = 1;
    for(int i=0;i<y;i++){
        answer = (answer*x)%p;
    }
    return answer%p;
}

signed main()
{ 
    freopen("shroompath.in", "r", stdin);
    scanf("%lld\n%lld%lld%lld", &subtest, &S, &X, &Y);
    
    ll ceilX = (S / X) + ((S % X) != 0);
    ll ceilY = (S/Y) + ((S % Y) != 0);
    
    freopen("shroompath.out", "w", stdout);
    printf("%lld\n", std::min((2 + ((ceilX/2 - 1) * (expo(2, ceilX/2 + 1)%MOD))%MOD + ceilX)%MOD,      (2 + (((ceilY-2)*(expo(2, ceilY))%MOD)%MOD + (expo(2, ceilY - 1) * ceilY)%MOD)%MOD + 1)%MOD));
    return 0;
}