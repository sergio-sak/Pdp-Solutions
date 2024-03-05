#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

const ll INF = 1e18;

ll N, M, S, T, P, Q, distwoq = 1e18, distwq = 1e18, distToP, ptoq, qtot;
std::vector<pi> graph[(size_t)(6*1e4 + 5)], graphQ[(size_t)(6*1e4 + 5)]; //graph[node] = {neighbour, weight}

pl dijkstra(int S, std::vector<pi> adj[(size_t)(6*1e4 + 5)]) {
    std::priority_queue<std::pair<ll, int>> q;
    ll dist[(size_t)(6*1e4 + 5)];
    bool vis[(size_t)(6*1e4 + 5)];

    for(int i = 1; i <= N; ++i) {
        dist[i] = INF;
        vis[i] = false;
    }
    dist[S] = 0;
    q.push({0, S});
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        if(u == Q && S == P) return {dist[Q], -1};
        if(u == T && S == Q) return {dist[T], -1};
        if(vis[u]) continue;
        for(auto edge : adj[u]) {
            int v, w; std::tie(v, w) = edge;
            if(vis[v]) continue;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
    return {dist[T], dist[P]};
}

int main()
{
    #ifdef CONTEST
        freopen("supgame.in", "r", stdin);
        freopen("supgame.out", "w", stdout);
    #else
        freopen("supgame.in", "r", stdin);
    #endif

    scanf("%d %d %d %d %d %d", &N, &M, &S, &T, &P, &Q);
    for(int i = 0; i < M; ++i) {
        int node, edge, weight;
        scanf("%d %d %d", &node, &edge, &weight);
        if(edge != Q && node != Q)
            graphQ[node].push_back({edge, weight});
        graph[node].push_back({edge, weight});
    }
    std::tie(distwoq, distToP) = dijkstra(S, graphQ);
    std::tie(ptoq, std::ignore) = dijkstra(P, graph);
    std::tie(qtot, std::ignore) = dijkstra(Q, graph);
    if(distwoq <= distToP + ptoq + qtot) printf("%lld\n", distwoq);
    else printf("%lld\n", distToP + ptoq + qtot);
    return 0;
}
