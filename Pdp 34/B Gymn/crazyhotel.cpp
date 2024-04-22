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

ll N, S, T, day, sum, ans, left = 1, right;
vll days, sums;

int main()
{
    #ifdef CONTEST
        freopen("crazyhotel.in", "r", stdin);
        freopen("crazyhotel.out", "w", stdout);
    #else
        freopen("crazyhotel.in", "r", stdin);
    #endif
    scanf("%lld %lld %lld", &N, &S, &T);

    days.pb(0);
    sums.pb(0);

    FOR(i, 0, N) {
        scanf("%lld", &day);
        days.pb(day);
        sum += day;
        sums.pb(sum);
    }

    for(left; left <= N; ++left) {
        if(right + 1 < left)
            right = left - 1;
        while(right + 1 <= N && days[right+1] <= T && sums[right+1] - sums[left-1] <= S){
            right++;
        }
        ans += right - left + 1;
    }

    printf("%lld\n", ans);
    return 0;
}
