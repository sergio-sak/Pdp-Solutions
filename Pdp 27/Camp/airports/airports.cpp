#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, M, K, cost = 0, costwithairports = 0;
vi connection((size_t)(1e4+4)), size((size_t)(1e4+4));
std::vector<std::tuple<int, int, int>> edges;
std::vector<pl> airports;

int find(int x) {
    while(x != connection[x]) x = connection[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) std::swap(a, b);
    size[a] += size[b];
    connection[b] = a;
}

int main()
{
    #ifdef CONTEST
        freopen("airports.in", "r", stdin);
        freopen("airports.out", "w", stdout);
    #else
        freopen("airports.in", "r", stdin);
    #endif
    
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges.push_back({b, 0, a});
    }
    
    for(int i = 0; i < K; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back({w, u, v});
    }
    std::sort(edges.begin(), edges.end());
    
    //airports
    for(int i = 1; i <= N; ++i) {
        connection[i] = i;
        size[i] = 1;
    }
    for(auto edge : edges){
        int u, v, w;
        std::tie(w, u, v) = edge;
        if(!same(u, v)) {
            unite(u, v);
            cost += w;
        }
    }

    for(int i = 1; i <= N; ++i) {
        connection[i] = i;
        size[i] = 1;
    }
    for(auto edge : edges){
        int u, v, w;
        std::tie(w, u, v) = edge;
        if(!same(u, v) && u != 0){
            unite(u, v);
            costwithairports += w;
        }
    }
    printf("%d\n", std::min(cost, costwithairports));
    return 0;
}
