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

ll fibonacci, indx;
vll fib(50), ans;

int main()
{
    #ifdef CONTEST
        freopen("fib6.in", "r", stdin);
        freopen("fib6.out", "w", stdout);
    #else
        freopen("fib6.in", "r", stdin);
    #endif
    scanf("%lld", &fibonacci);

    fib[0] = 0;
    fib[1] = 1;
    indx = 1;
    for(int i = 2; i <= 46; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] < fibonacci)
            indx++;
    }

    while(fibonacci > 0) {
        fibonacci -= fib[indx];
        ans.pb(fib[indx]);
        while(indx > 0 && fib[indx] > fibonacci) {
            indx--;
        }
    }

    if(ans.size() <= 6) {
        printf("%lld ", ans.size());
        FOR(i, 0, ans.size()) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    else
        printf("impossible\n");
    return 0;
}
