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

std::vector<std::vector<bool>> grid(505, std::vector<bool>(505));
std::vector<pllll> adj[MAXN];
ll N, tasos, golfo;
char chr;

ll convert(ll i, ll j) {
    return (i-1)*N+j;
}

bool inbounds(ll i, ll j) {
    return i >= 1 && i <= N && j <= N && j >= 1;
}

ll dist[MAXN];
bool vis[MAXN];
std::priority_queue<pllll> q;

ll dijkstra(ll s) {
    FOR(i, 1, N*N+5) {
        dist[i] = INF;
        vis[i] = false;
    }

    dist[s] = 0;
    q.push({0, s});

    while(!q.empty()) {
        ll u = q.top().se; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto pp : adj[u]) {
            ll v, w;
            std::tie(w, v) = pp;
            if(vis[v]) continue;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if(v == golfo)
                    return dist[v];
                q.push({-dist[v], v});
            }
        }
    }
    return dist[golfo];
}

int main()
{
    freopen("golfo.in", "r", stdin);
    freopen("golfo.out", "w", stdout);
    scanf("%lld\n", &N);

    FOR(i, 1, N+1) {
        FOR(j, 1, N+1) {
            scanf("%c", &chr);
            if(chr == 'X') grid[i][j] = true;
            if(chr == 'T') tasos = convert(i, j);
            if(chr == 'G') golfo = convert(i, j);
        }
        getchar();
    }

    FOR(i, 1, N+1) {
        FOR(j, 1, N+1) {
            if(!grid[i][j]) {
                if(inbounds(i+1, j) && !grid[i+1][j]) {
                    adj[convert(i, j)].pb({0, convert(i+1, j)});
                }
                if(inbounds(i-1, j) && !grid[i-1][j]) {
                    adj[convert(i, j)].pb({2, convert(i-1, j)});
                }
                if(inbounds(i, j+1) && !grid[i][j+1]) {
                    adj[convert(i, j)].pb({1, convert(i, j+1)});
                }
                if(inbounds(i, j-1) && !grid[i][j-1]) {
                    adj[convert(i, j)].pb({1, convert(i, j-1)});
                }
            }
        }
    }

    // std::cout<<golfo<<std::endl;
    // FOR(i, 1, N*N+1) {
    //     std::cout<<i<<": ";
    //     for(auto el : adj[i]){
    //             std::cout<<el.se<<" ";
    //     }
    //     std::cout<<std::endl;
    // }

    ll ans = dijkstra(tasos);
    if(ans == INF) printf("IMPOSSIBLE");
    else printf("%lld\n", ans);
    return 0;
}