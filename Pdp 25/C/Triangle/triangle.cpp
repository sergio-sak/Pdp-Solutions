#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 1000005
#define EPS 1e-9

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pllll;
typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::unordered_map<int , int> mii;
typedef std::unordered_map<ll , ll> mllll;
typedef std::unordered_map<char , int> mci;
typedef std::unordered_map<char , ll> mcll;

ll N, num;
std::vector<vll> triangle;
ll memo[1001][1001];
vll cur;

ll solve(ll i, ll j) {
    if(memo[i][j]) return memo[i][j];
    if(i == N-1) return triangle[i][j];
    return memo[i][j] = triangle[i][j] + std::max(solve(i+1, j), solve(i+1, j+1));
}

int main()
{
    #ifdef CONTEST
        freopen("triangle.in", "r", stdin);
        freopen("triangle.out", "w", stdout);
    #else
        freopen("triangle.in", "r", stdin);
    #endif
    scanf("%lld", &N);
    FOR(i, 1, N+1) {
        FOR(j, 0, i) {
            scanf("%lld", &num);
            cur.pb(num);
        }
        triangle.pb(cur);
        cur.clear();
    }    


    printf("%lld\n", solve(0, 0));
    return 0;
}
// for(auto outer : triangle) {
//     for(auto inner : outer) {
//         std::cout<<inner<<" ";
//     }
//     std::cout<<std::endl;
// }
