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

ll N, j, num, max;
vll nums;

int main()
{
    #ifdef CONTEST
        freopen("prevdiv.in", "r", stdin);
        freopen("prevdiv.out", "w", stdout);
    #else
        freopen("prevdiv.in", "r", stdin);
    #endif
    
    scanf("%lld", &N);
    FOR(i, 0, N) {
        scanf("%lld", &num);
        nums.pb(num);
    }

    FOR(i, 0, N) {
        if(nums[i] > max) {
            while(i > j) {
                if(nums[i] % nums[j] != 0) break;
                ++j;
            }
            if(j == i) max = nums[i];
        }
    }

    printf("%lld\n", max);
    return 0;
}
