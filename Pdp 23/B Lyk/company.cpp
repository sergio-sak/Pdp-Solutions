#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 5005
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

ll N, num, male, female, root;
std::vector<bool> genders(MAXN);
vll graph[MAXN];
char gender;

void dfs(ll u, ll e) {
    for(auto v : graph[u]) {
        if(v != e) {
            if(genders[v])  male++;
            else female++;
            dfs(v, u);
        }
    }
}

int main()
{
    #ifdef CONTEST
        freopen("company.in", "r", stdin);
        freopen("company.out", "w", stdout);
    #else
        freopen("company.in", "r", stdin);
    #endif
    scanf("%lld", &N);

    FOR(i, 1, N+1) {
        scanf("%lld %c\n", &num, &gender);
        graph[num].pb(i);
        genders[i] = (gender == 'm') ? true : false;
        if(num == 0) root = i;
    }
    
    dfs(root, 0);
    
    printf("%lld", male - female);
    return 0;
}
