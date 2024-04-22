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

std::vector<pllll> right;
ll N, num, ans, left;
vll nums;

int main()
{
    #ifdef CONTEST
        freopen("skitrip.in", "r", stdin);
        freopen("skitrip.out", "w", stdout);
    #else
        freopen("skitrip.in", "r", stdin);
    #endif

    scanf("%lld", &N);
    
    for(int i = 0; i < N; ++i) {
        scanf("%lld ", &num);
        nums.pb(num);
    }

    right.pb({nums[N-1], N-1});
    for(int i = N-2; i >= 0; --i) {
        if(nums[i] > right.back().fi) {
            right.pb({nums[i], i});
        }
    }

    left = nums[0] + 1;
    ll j = right.size()-1;

    for(ll i = 0; i < N; ++i) {
        if(left > nums[i]){
            while(j > 0 && nums[i] <= right[j-1].fi) {
                j--;
            }
            ans = std::max(ans, right[j].se - i);
            left=nums[i];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
