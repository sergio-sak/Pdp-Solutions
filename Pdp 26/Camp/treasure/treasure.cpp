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
#define MAXN 300'000
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

struct leaf {
    
};

ll N, Q, inpt[MAXN];
ll* seg = new ll[4*(std::bit_ceil((unsigned)N))];

void Build(int ind = 1, int l = 0, int r = N-1) {
    if(l == r) {
        seg[ind] = inpt[l];
        return;
    }

    int mid = l + (r-l)/2;
    Build(2*ind, l, mid);
    Build(2*ind+1, mid+1, r);

    seg[ind] = ((seg[2*ind]) % MOD + (seg[2*ind+1]) % MOD) % MOD;
}

void Update(int pos, ll val, int ind = 1, int l = 0, int r = N-1) {
    if(l == r) {
        seg[ind] = val;
        return;
    }

    int mid = l + (r-l)/2;
    if(pos <= mid) Update(pos, val, 2*ind, l, mid);
    else Update(pos, val, 2*ind+1, mid+1, r);

    seg[ind] = ((seg[2*ind]) % MOD + (seg[2*ind+1]) % MOD) % MOD;
}

ll Query(int from, int to, int ind = 1, int l = 0, int r = N-1) {
    if(l == from && r == to) return seg[ind];

    int mid = l + (r - l)/2;
    if(to <= mid) return Query(from, to, 2*ind, l, mid);
    else if(from > mid) return Query(from, to, 2*ind+1, mid+1, r);
    else return ((Query(from, mid, 2*ind, l, mid)) % MOD + (Query(mid+1, to, 2*ind+1, mid+1, r)) % MOD) % MOD;
}

signed main()
{
    sl(N); sl(Q);
    for(int i = 0; i < N; ++i) {
        sl(inpt[i]);
        inpt[i] *= (i+1);
    } Build();

    while(Q--) {
        int q, a, b;
        sl(q); sl(a); sl(b);
        if(q == 0) Update(a-1, b);
        else printf("%lld", ((Query(a-1, b-1)) % MOD)/a);
    }

    delete[] seg;
    return 0;
}