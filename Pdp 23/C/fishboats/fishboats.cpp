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

ll N, M, best;
vll left, right;

void solve(ll i, ll j, bool isleft, ll dist, ll total) {
    if(M < dist) return;
    best = std::max(best, total);
    if(i + 1 < left.size()) {
        ll new_dist = dist + (isleft ? (left[i+1] - left[i]) : (left[i + 1] + right[j]));
        solve(i+1, j, true, new_dist, total + (M-new_dist));
    }
    if(j + 1 < right.size()) {
        ll new_dist = dist + ((!isleft) ? (right[j+1] - right[j]) : (right[j + 1] + left[i]));
        solve(i, j + 1, false, new_dist, total + (M-new_dist));
    }
}

int main()
{
    #ifdef CONTEST
        freopen("fishboats.in", "r", stdin);
        freopen("fishboats.out", "w", stdout);
    #else
        freopen("fishboats.in", "r", stdin);
    #endif
    scanf("%lld%lld", &N, &M);

    left.pb(0);
    right.pb(0);
    FOR(i, 0, N) {
        ll num;
        scanf("%lld", &num);
        if(num < 0) left.pb(-num);
        else right.pb(num);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());


    solve(0, 0, true, 0, 0);

    printf("%lld\n", best);
    return 0;
}
