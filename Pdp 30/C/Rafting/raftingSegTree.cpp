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

int N;

int *seg , *inpt, *result;

int size() {
    int n = 1;
    while(n < N) n <<= 1;
    return n;
}


void Build( int ind = 1, int l = 1, int r = N) {
    if(l == r) {
        seg[ind] = 1;
        return;
    }

    int mid = l + (r-l)/2;
    Build(2*ind, l, mid);
    Build(2*ind+1, mid+1, r);

    seg[ind] = seg[2*ind] + seg[2*ind+1];
}

void Update(int pos, int ind = 1, int l = 1, int r = N) {
    if(l == r) {
        seg[ind] = 0;
        return;
    }

    int mid = l + (r-l)/2;
    if(pos <= mid) Update(pos, 2*ind, l, mid);
    else Update(pos, 2*ind+1, mid+1, r);

    seg[ind] = seg[2*ind] + seg[2*ind+1];
}

int Query(int k, int ind = 1, int l = 1, int r = N) {
    if(l == r) return l;

    int mid = l + (r-l)/2;
    if(seg[2*ind] >= k) return Query(k, 2*ind, l, mid);
    else return Query(k - seg[2*ind], 2*ind+1, mid+1, r);
}

signed main()
{
    si(N);
    seg = new int[4*size()];
    inpt = new int[size()];
    result = new int[size()];
    
    for(int i = 1; i <= N; ++i) {
        si(inpt[i]);
    } Build();

    for(int i = N; i >= 1; --i) {
        int indx = Query(inpt[i]);
        result[indx] = i;
        Update(indx);
    }

    for(int i = 1; i <= N; ++i) {
        printf("%d ", result[i]);
    }

    delete[] seg;
    delete[] inpt;
    delete[] result;
    return 0;
}
