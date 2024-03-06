#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

const ll INF = 1e10;
ll N, M, S, T;
std::vector<pl> graph[(size_t)(1e5+5)];
bool vis[(size_t)(1e5+5)];
ll dist[(size_t)(1e5+5)];
std::priority_queue<std::pair<ll, int>> q;

void dijkstra(int s) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
        vis[i] = false;
    }

    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto edge : graph[u]) {
            ll v, w;
            std::tie(v, w) = edge;
            if(dist[u] + (ll)w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
}

int main()
{
    #ifdef CONTEST
        freopen("shortpowtwo.in", "r", stdin);
        freopen("shortpowtwo.out", "w", stdout);
    #else
        freopen("Testcases/shortpowtwo/shortpowtwo.in4", "r", stdin);
    #endif
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i < M; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        graph[a].push_back({b, std::pow(2, c)});
    }
    scanf("%lld %lld", &S, &T);
    dijkstra(S);
    if(dist[T] == INF) {
        printf("-1\n");
    } else {
        dist[T] = dist[T] % (ll)(1e9+7);
       printf("%lld\n", dist[T]);
    }
    return 0;
}
