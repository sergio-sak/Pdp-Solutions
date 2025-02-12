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

int type, N, D, D1, D2, a, b;

struct judge {
    int grand(int a, int b) {
        return rand() % (b - a + 1) + a;
    }

    void getRand(){
        a = grand(1, N);
        b = grand(a + 1, N);
    }
    int getSubtask() {
        // return grand(1, 8);
        return 4;
    }
    int getN() {
        return grand(3, 1000);
    }
    int getD() {
        if(type <= 3) return b - a;
        return -1;
    }
    int query(int X){
        return std::abs(X-a) + std::abs(X-b);
    }
    bool answer(int A, int B){
        return A == a && B == b;
    }
};

signed main()
{
    judge j;
    srand(time(0));
    type = j.getSubtask();
    N = j.getN();
    j.getRand();
    D = j.getD();

    printf("a: %d b: %d N: %d D: %d type: %d\n", a, b, N, D, type);

    if(type > 3) {
        D1 = j.query(1);
        D2 = j.query(N);

        std::cout<<"D1: "<<D1<<" D2: "<<D2<<"\n";

        for(int A = 1; A < N; ++A) {
            for(int B = A + 1; B <= N; ++B) {

                if( (std::abs(1 - A) + std::abs(1 - B) == D1) && (std::abs(N - A) + std::abs(N - B) == D2) ) {
                    j.answer(A, B);
                    printf("Mine: %d %d Ans: %d %d\n", A, B, a, b);
                    // return 0;
                }

            }
        }
        
    } else {
        D1 = j.query(1);
        
        for(int A = 1; A < N; ++A) {
            for(int B = A + 1; B <= N; ++B) {
                if((std::abs(1 - A) + std::abs(1 - B) == D1) && (B - A == D)) {
                    j.answer(A, B);
                    printf("Mine: %d %d Ans: %d %d\n", A, B, a, b);
                    return 0;
                }
            }
        }
    }

    return 0;
}
