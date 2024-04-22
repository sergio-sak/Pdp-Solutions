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

std::unordered_map<ll, pllll> hmap;
ll N, odd, num, ans;
vll oddeven;

int main()
{
    #ifdef CONTEST
        freopen("oddeven.in", "r", stdin);
        freopen("oddeven.out", "w", stdout);
    #else
        freopen("testcases/oddeven/oddeven.in6", "r", stdin);
    #endif
    scanf("%lld", &N);

    oddeven.pb(0);
    hmap[0].fi = 0;

    FOR(i, 1, N+1) {
        scanf("%lld", &num);
        if(num&1) odd++;
        else odd--;
        oddeven.pb(odd);
        if(hmap.find(odd) == hmap.end()) hmap[odd].fi = i;
        else hmap[odd].se = i;
    }


    for(auto cur : oddeven) {
        ans = std::max(ans, hmap[cur].se - hmap[cur].fi);
    }

    printf("%lld\n", ans);
    return 0;
}
