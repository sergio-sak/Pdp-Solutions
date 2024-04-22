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

ll A, M, ref1, ref2, phase, pos1, pos2;
vll phases;

int main()
{
    #ifdef CONTEST
        freopen("lines_man.in", "r", stdin);
        freopen("lines_man.out", "w", stdout);
    #else
        freopen("lines_man.in", "r", stdin);
    #endif
    scanf("%lld\n%lld", &A, &M);
    pos1 = pos2 = A/2;

    FOR(i, 0, M) {
        scanf("%lld", &phase);
        ll cur1 = std::min(A/2, phase);
        ref1 += std::abs(cur1 - pos1);
        pos1 = cur1;

        ll cur2 = std::max(phase, A/2);
        ref2 += std::abs(cur2 - pos2);
        pos2 = cur2;
    }
    printf("%lld %lld\n", ref1, ref2);
    return 0;
}