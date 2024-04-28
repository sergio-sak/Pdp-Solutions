#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 1010
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

ll N, M;
std::vector<pllll> moves = {
    {1, -2},
    {-1, -2},
    {2, -1},
    {2, 1},
    {-2, -1},
    {-2, 1},
    {1, 2},
    {-1, 2}
};

bool seen[MAXN][MAXN];
ll dist[MAXN][MAXN];
bool inbound(ll y, ll x) {
    return x >= 1 && x <= M && y >= 1 && y <= N;
}

ll bfs(ll i, ll j) {
    std::queue<pllll> q;
    seen[i][j] = true;
    dist[i][j] = 0;
    q.push({i, j});
    while(!q.empty()) {
        pllll u = q.front(); q.pop();
        ll x, y;
        std::tie(y, x) = u;

        for(auto move : moves) {
            if(inbound(y + move.fi, x + move.se) && !seen[y + move.fi][x + move.se]) {
                q.push({y + move.fi, x + move.se});
                dist[y + move.fi][x + move.se] = dist[y][x] + 1;
                seen[y + move.fi][x + move.se] = true;
            }
        }
    }
    return dist[1][M];
}

int main()
{
    #ifdef CONTEST
        freopen("knight.in", "r", stdin);
        freopen("knight.out", "w", stdout);
    #else
        freopen("knight.in", "r", stdin);
    #endif
    
    scanf("%lld %lld", &N, &M);
    printf("%lld\n", bfs(N, 1));
    return 0;
}
