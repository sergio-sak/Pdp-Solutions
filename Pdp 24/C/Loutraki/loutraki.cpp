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

ll N, ans, coordinate_x, coordinate_y, distinct;
std::vector<pllll> coordinates;
std::map<pllll, ll> freq;

bool sortx(pllll p1, pllll p2) {
    if(p1.fi == p2.fi)
        return p1.se < p2.se;
    return p1.fi < p2.fi;
}

bool sorty(pllll p1, pllll p2) {
    if(p1.se == p2.se)
        return p1.fi < p2.fi;
    return p1.se < p2.se;
}

int main()
{
    #ifdef CONTEST
        freopen("loutraki.in", "r", stdin);
        freopen("loutraki.out", "w", stdout);
    #else
        freopen("loutraki.in", "r", stdin);
    #endif
    scanf("%lld", &N);

    FOR(i, 0, N) {
        scanf("%lld %lld", &coordinate_x, &coordinate_y);
        coordinates.pb({coordinate_x, coordinate_y});
    }

    std::sort(coordinates.begin(), coordinates.end(), sortx);

    freq[coordinates[0]]++;
    distinct = coordinates[0].fi;
    FOR(i, 1, N) {
        if(coordinates[i].fi != distinct) {
            distinct = coordinates[i].fi;
            freq[coordinates[i]]++;
        }
    }

    std::sort(coordinates.begin(), coordinates.end(), sorty);

    freq[coordinates[0]]++;
    distinct = coordinates[0].se;
    FOR(i, 1, N) {
        if(coordinates[i].se != distinct) {
            distinct = coordinates[i].se;
            freq[coordinates[i]]++;
        }
    }

    for(auto coordinate : freq) {
        if(coordinate.se == 2)
            ans++;
    }

    printf("%lld\n", ans);
    return 0;
}