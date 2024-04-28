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

std::unordered_map<ll, bool> hmap;
ll N, num, sum, ans;
vll sums;

int main()
{
    #ifdef CONTEST
        freopen("intvsum.in", "r", stdin);
        freopen("intvsum.out", "w", stdout);
    #else
        freopen("intvsum.in", "r", stdin);
    #endif
    scanf("%lld\n", &N);
    sums.pb(0);

    FOR(i, 1, N+1) {
        scanf("%lld", &num);
        sum += num;
        sums.pb(sum);
        hmap[2*sums[i] - sums[i-1]] = true;
    }

    FOR(i, 1, N+1) {
        if(hmap.find(2*sums[i-1] - sums[i]) != hmap.end())
            ans = i;
    }

    printf("%lld\n", ans);
    return 0;
}
