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

ll N, Q, query, num, i, j;
vll nums;

int main()
{
    #ifdef CONTEST
        freopen("sumpair.in", "r", stdin);
        freopen("sumpair.out", "w", stdout);
    #else
        freopen("sumpair.in", "r", stdin);
    #endif
    scanf("%lld %lld", &N, &Q);
    FOR(i, 0, N) {
        scanf("%lld", &num);
        nums.pb(num);
    }

    std::sort(nums.begin(), nums.end());
    while(Q--){
        scanf("%lld", &query);
        i = 0;
        j = nums.size()-1;
        while(i < j) {
            if(nums[i] + nums[j] == query) {
                printf("true\n");
                break;
            }
            if(nums[i] + nums[j] > query)
                j--;
            else
                i++;
        }
        if(i == j)
            printf("false\n");
    }
    return 0;
}
