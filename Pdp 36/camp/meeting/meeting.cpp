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


struct coordinate {
    ll x, y;
};

vi psX, psY;
ll N, min = INT64_MAX;
std::vector<coordinate> coordinates_x, coordinates_y;

bool comp_x(coordinate c1, coordinate c2) {
    return c1.x < c2.x;
}

bool comp_y(coordinate c1, coordinate c2) {
    return c1.y < c2.y;
}

ll binarySearch(ll x) {
    int l = 0, h = N-1, mid;
    while(l <= h) {
        mid = l + (h-l)/2;
        if(coordinates_y[mid].y > x) h = mid-1;
        else if(coordinates_y[mid].y < x) l = mid+1;
        else return mid;
    }
    return -1;
}

signed main()
{
    sl(N);
    
    coordinates_x.pb({0, 0});
    for(int i = 1; i <= N; ++i) {
        ll x, y; sl(x); sl(y);
        coordinates_x.pb({x, y});
    } coordinates_y = coordinates_x;

    std::sort(all(coordinates_x), comp_x); 
    std::sort(all(coordinates_y), comp_y); 

    psX.resize(N+1); psY.resize(N+1);
    for(int i = 1; i <= N; ++i) {
        psX[i] = psX[i-1] + coordinates_x[i].x;
        psY[i] = psY[i-1] + coordinates_y[i].y;
    }

    for(int i = 1; i <= N; ++i) {
        ll x = coordinates_x[i].x, y = coordinates_x[i].y;
        ll index = binarySearch(y), sum = 0;
        sum = N*x - psX[i];
        sum += (psX[N] - psX[i]) - N*x;

        // sum += N*y - psY[index];
        // sum += (psY[N] - psY[index]) - N*y;

        std::cout<<sum<<"\n";
        min = std::min(min, sum);
    }
    
    printf("%lld\n", min);
    return 0;
}
