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

ll N, M, K, day, ans, left, right, responsiblities;
vll days;

int main()
{
    #ifdef CONTEST
        freopen("maketime.in", "r", stdin);
        freopen("maketime.out", "w", stdout);
    #else
        freopen("maketime.in", "r", stdin);
    #endif
    scanf("%lld %lld %lld", &N, &M, &K);
    days.resize(N+3);

    FOR(i, 0, M) {
        scanf("%lld", &day);
        days[day]++;
    }

    right = 0;
    FOR(left, 1, N+1) {
        while(right + 1 <= N && responsiblities <= K) {
            right++;
            if(days[right]) responsiblities += days[right];
            if(responsiblities > K)
                break;
            ans = std::max(ans, right - left + 1);
        }
        if(days[left]) responsiblities -= days[left];
    }

    printf("%lld\n", ans);
    return 0;
}
