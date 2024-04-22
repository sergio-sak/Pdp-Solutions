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

ll N, num, total;
ll memo[10001][10001][2];
vll nums;

ll dp(ll i, ll j, bool isfirstplayer) {
    if(memo[i][j][(int)isfirstplayer]) return memo[i][j][(int)(int)isfirstplayer];
    if(i == j && isfirstplayer) return nums[i];
    else if(i == j && !isfirstplayer) return -nums[i];
    if(isfirstplayer)
        return memo[i][j][(int)isfirstplayer] = std::max(nums[i] + dp(i+1, j, false), dp(i, j-1, false) + nums[j]);
    else
        return memo[i][j][(int)isfirstplayer] = std::min(dp(i+1, j, true) - nums[i], dp(i, j-1, true) - nums[j]);
}


int main()
{
    #ifdef CONTEST
        freopen("listgame.in", "r", stdin);
        freopen("listgame.out", "w", stdout);
    #else
        freopen("listgame.in", "r", stdin);
    #endif
    scanf("%lld", &N);

    FOR(i, 0, N) {
        scanf("%lld", &num);
        nums.pb(num);
        total += num;
    }
    printf("%lld\n", (dp(0, N-1, true) + total) / 2);
    return 0;
}