#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, M, roads, components = 0;
bool connected = false;
vi graph[(size_t)(1e6+6)];
bool vis[(size_t)(1e6+6)];

void dfs(int x) {
    std::stack<int> s;
    vis[x] = true;
    s.push(x);
    while(!s.empty()) {
        int u = s.top(); s.pop();
        for(int v : graph[u]) {
            if(vis[v]) continue;
            vis[v] = true;
            s.push(v);
        }
    }
}


void dfs_help() {
    for(int i = 1; i <= N; i++) {
        if(!vis[i] && roads > 0) {
            roads--;
            dfs(i);
        }
        else if(!vis[i]) {
            components++;
            connected = true;
            dfs(i);
        }
    }

}
int main()
{
    #ifdef CONTEST
        freopen("villages.in", "r", stdin);
        freopen("villages.out", "w", stdout);
    #else
        freopen("Testcases/village.in1", "r", stdin);
    #endif
    
    scanf("%lld %lld %lld", &N, &M, &roads);

    for(int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs_help();
    if(!connected) components++;
    printf("%lld\n", components);
    return 0;
}
