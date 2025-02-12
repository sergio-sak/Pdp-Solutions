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
#include <iomanip>
#include <inttypes.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,Ofast")

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

struct contract {
  int X, Y, Z;  
};

int subtask, N, X, Y, Z, sum;
std::vector<contract> contracts;

bool cmp(contract c1, contract c2) {
    if(c1.Z - c1.Y == c2.Z - c2.Y) {
        if(c1.Y - c1.X == c2.Y - c2.X)
            return c1.X > c2.X;
        return c1.Y - c1.X > c2.Y - c2.X;
    }
    return c1.Z - c1.Y > c2.Z - c2.Y;
}

void debug() {
    for(auto current : contracts) {
        std::cout<<current.X<<" "<<current.Y<<" "<<current.Z<<"\n";
    }
}

signed main()
{
    freopen("hiring.in", "r", stdin);
    si(subtask);
    si(N); si(X); si(Y); si(Z);

    contracts.resize(N);
    
    for(contract&current : contracts) {
        si(current.X); si(current.Y); si(current.Z);
    }

    std::sort(all(contracts), cmp);

    // for(contract&current : contracts) {
    //     si(current.X); si(current.Y); si(current.Z);
    // }

    // debug();

    int ind = 0;
    while(Z-- && ind < N) {
        sum += contracts[ind++].Z;
    }
    while(Y-- && ind < N) {
        sum += contracts[ind++].Y;
    }
    while(X-- && ind < N) {
        sum += contracts[ind++].X;
    }

    freopen("hiring.out", "w", stdout);
    printf("%d\n", sum);
    return 0;
}
