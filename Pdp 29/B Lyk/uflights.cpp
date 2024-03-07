#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, M;
std::vector<std::tuple<int, int, int>> edges((size_t)(1e5+5));
vi connection((size_t)(1e5+5)), size((size_t)(1e5+5));

int find(int a) {
    while(a != connection[a]) a = connection[a];
    return a;
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

int kruskal() {
    std::sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto edge :edges) {
        int u, v, w;
        std::tie(w, u, v) = edge;
        if(!same(u, v)) {
            unite(u, v);
            cost += w;
        }
    }
    return cost;
}

int main()
{
    #ifdef CONTEST
        freopen("uflights.in", "r", stdin);
        freopen("uflights.out", "w", stdout);
    #else
        freopen("uflights.in", "r", stdin);
    #endif
    
    scanf("%lld %lld", &N, &M);

    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back(std::make_tuple(c, a, b));
    }
    for(int i = 1; i <= N; i++) {
        connection[i] = i;
        size[i] = 1;
    }
    printf("%d\n", kruskal());
    return 0;
}