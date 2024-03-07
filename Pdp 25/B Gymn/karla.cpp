#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, M, res = 0;
std::vector<std::vector<bool>> graph;


void bfs(int i, int j) {
    res++;
    std::queue<pi> q;
    q.push({i, j});
    graph[i][j] = true;
    while(!q.empty()) {
        pi p = q.front();
        q.pop();
        if(p.first+1 < N && !graph[p.first+1][p.second]) {
            q.push({p.first+1, p.second});
            graph[p.first+1][p.second] = true;
        }
        if(p.first-1 >= 0 && !graph[p.first-1][p.second]) {
            q.push({p.first-1, p.second});
            graph[p.first-1][p.second] = true;
        }
        if(p.second+1 < N && !graph[p.first][p.second+1]) {
            q.push({p.first, p.second+1});
            graph[p.first][p.second+1] = true;
        }

        if(p.second-1 >= 0 && !graph[p.first][p.second-1]) {
            q.push({p.first, p.second-1});
            graph[p.first][p.second-1] = true;
        }
    }
}



int main()
{
    #ifdef CONTEST
        freopen("karla.in", "r", stdin);
        freopen("karla.out", "w", stdout);
    #else
        freopen("karla.in1", "r", stdin);
    #endif

    scanf("%lld %lld", &N, &M);
    for(int i = 0; i < M; i++)
    graph.resize(N, std::vector<bool>(N, false));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            int x;
            scanf("%d", &x);
            if(x <= M) graph[i][j] = true;
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!graph[i][j]){
                bfs(i, j);
            }
            
        }
    }
    printf("%lld\n", res);
    return 0;
}