#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 10005
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

std::vector<pllll> adj[MAXN]; //{w, u}
ll N, M, S, T, B, ans;
vll dist(MAXN), prev(MAXN);
bool vis[MAXN];

void dijkstra(ll s) {
    std::priority_queue<pllll> q, roads;
    FOR(i, 0, N+1) {
        dist[i] = INF;
    }

    dist[s] = 0;
    vis[s] = true;
    while(!q.empty()) {
        ll u = q.top().se; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto pr : adj[u]) {
            ll v, w;
            std::tie(w, v) = pr;
            if(vis[v]) continue;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
                prev[v] = u;
            }
        }
    }
}

int main()
{
    #ifdef CONTEST
        freopen("shortcuts.in", "r", stdin);
        freopen("shortcuts.out", "w", stdout);
    #else
        freopen("shortcuts.in", "r", stdin);
    #endif
    scanf("%lld %lld %lld %lld %lld", &N, &M, &S, &T, &B);

    FOR(i, 0, M) {
        ll a, b, w;
        scanf("%lld %lld %lld", &a, &b, &w);
        adj[a].pb({w, b});
    }
    dijkstra(S);

    ll help = T;
    std::stack<ll> s;
    while(help != S) {
        help = prev[help];
        s.push(help);
    }

    std::cout<<S<<" ";
    while(!s.empty()) {
        std::cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
