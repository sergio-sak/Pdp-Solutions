#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
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

ll N, target, count, num;
mllll hmap;

int main()
{
    #ifdef CONTEST
        freopen("sumx.in", "r", stdin);
        freopen("sumx.out", "w", stdout);
    #else
        freopen("sumx.in", "r", stdin);
    #endif
    
    scanf("%lld %lld", &N, &target);
    FOR(i, 0, N) {
        scanf("%lld", &num);
        count += hmap[target - num];
        hmap[num]++;
    }

    printf("%lld\n", count);
    return 0;
}
