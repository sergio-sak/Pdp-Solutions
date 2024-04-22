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

ll N, K, num, sum, j, ans;
vll nums;

int main()
{
    #ifdef CONTEST
        freopen("efimerides.in", "r", stdin);
        freopen("efimerides.out", "w", stdout);
    #else
        freopen("efimerides.in", "r", stdin);
    #endif
    
    scanf("%lld %lld", &N, &K);
    bool seen[N+1];

    FOR(i, 0, N) {
        scanf("%lld", &num);
        nums.pb(num);
    }

    FOR(i, 0, N) {
        if(seen[i]) continue;
        sum = 0;
        j = i;
        
        do {
            sum += nums[j];
            j = (j+K) % N;
            seen[j] = true;
        } while(i != j);
        ans = std::max(ans, sum);
    }

    printf("%lld\n", ans);
    return 0;
}
