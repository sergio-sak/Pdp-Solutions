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
#define MOD 1000000007
#define INF 1'000'000'000'000

#define ll int64_t
#define int int32_t
#define short int16_t

#define si(n) scanf("%" PRId32, &n);
#define sl(n) scanf("%" PRId64, &n);
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

ll _, N;

signed main()
{
    freopen("oddsum.in", "r", stdin);
    freopen("oddsum.out", "w", stdout);
    
    sl(_);
    while(_--) {
        sl(N); ll sum = 0;
        vll oddPositive;
        ll sumOfEverything = 0, sumExludingLast = 0, oddNegative = -0xffffff;

        for(ll i = 0, num; i < N; ++i) {
            sl(num);
            if(num % 2 != 0) {
                if(num <= 0) oddNegative = std::max(oddNegative, num);
                else oddPositive.pb(num);
            } else if(num > 0) sum += num;
        }
        
        if(oddPositive.size() % 2 != 0) {
            for(ll odd : oddPositive) {sum += odd;}
        } else {
            if(oddNegative == -0xffffff && oddPositive.size() == 0) {
                printf("IMPOSSIBLE\n");
                continue;
            }
            
            std::sort(rall(oddPositive));
            
            if(oddPositive.size() == 0) {
                printf("%ld\n", sum + oddNegative);
                continue;
            }

            for(int i = 0; i < (int)oddPositive.size()-1; ++i) {sumExludingLast += oddPositive[i];}

            if(oddNegative == -0xffffff) {
                printf("%ld\n", sumExludingLast + sum);
                continue;
            }

            for(ll odd : oddPositive) {sumOfEverything += odd;}
            sumOfEverything += oddNegative;
        }
        printf("%ld\n", std::max(sumExludingLast, sumOfEverything) + sum);
    }
    return 0;
}
