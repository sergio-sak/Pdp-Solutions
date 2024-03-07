#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, M;
std::vector<std::tuple<int, int,int>> edges;
vi connections((size_t)(1e4+4)), sizes((size_t)(1e4+4));

int find(int a) {
    while(a != connections[a]) a = connections[a];
    return a;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(sizes[a] < sizes[b]) std::swap(a, b);
    sizes[a] += sizes[b];
    connections[b] = a;
}

int kruskal() {
    int max;
    std::sort(edges.begin(), edges.end());
    for(auto edge : edges) {
        int u, v, w;
        std::tie(w, u, v) = edge;
        if(!same(u, v)){
            unite(u, v);
            max = w;
        }
    }
    return max;
}

int main()
{
    #ifdef CONTEST
        freopen("smalltank.in", "r", stdin);
        freopen("smalltank.out", "w", stdout);
    #else
        freopen("smalltank.in", "r", stdin);
    #endif
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({c, a, b});
    }


    for(int i = 1; i <= N; i++) {
        connections[i] = i;
        sizes[i] = 1;
    }

    printf("%d\n", kruskal());
    return 0;
}
