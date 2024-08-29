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
#define MAXN 1'000'005
#define MOD 1'000'000'007
#define INF 1'000'000'000'000

#define ll int_fast64_t
#define int int_fast32_t
#define short int_fast16_t

#define si(n) scanf("%" PRIdFAST32"\n", &n);
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

int N, a, b, c;
vi nums, prefix;

void calc_sums(int left, int right) {
    a = prefix[left];
    b = prefix[right] - prefix[left-1];
    c = prefix[N] - prefix[right - 1];
}

signed main()
{
    #ifdef CONTEST
        freopen("share.in", "r", stdin);
        freopen("share.out", "w", stdout);
    #endif
    
    si(N); nums.resize(N+1); prefix.resize(N+1);
    for(int i = 1; i <= N; ++i) {
        si(nums[i]);
        prefix[i] = prefix[i-1] + nums[i];
    }

    int left = 0, right = N-1;
    calc_sums(left, right);
    while(b > a && b > c) {
        if(a + nums[left + 1] < b && a + nums[left+1] <= c + nums[right]) {
            left++;
        } else if(c + nums[right] < b && c + nums[right] <= a + nums[left+1]) {
            right--;
        } else {
            break;
        }
        calc_sums(left, right);
    }

    printf("%d\n", std::max(a, std::max(b, c)));
    return 0;
}