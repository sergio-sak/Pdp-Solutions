/* USER: user081.36pdp
LANG: C++
TASK: publib */

#include <iostream>
#include <inttypes.h>
#include <vector>
#include <queue>

uint16_t N, M, maxdist= 0, minmaxdist = 2001, a, b;
std::vector<uint16_t> graph[2001], distance(2001);
bool seen[2001];

void bfs(uint16_t x){
    std::queue<uint16_t> q;
    seen[x] = true;
    distance[x] = 0;
    q.push(x);
    while(!q.empty()){
        uint16_t u = q.front(); q.pop();
        for(uint16_t v : graph[u]){
            if(seen[v]) continue;
            seen[v] = true;
            distance[v] = distance[u] + 1;
            maxdist = distance[v];
            if(distance[v] >= minmaxdist)return;
            q.push(v);
        }
    }
    minmaxdist = std::min(minmaxdist, maxdist);
}
int main()
{
    freopen("publib.in", "r", stdin); //Got 1st place for Lyceum
    freopen("publib.out", "w", stdout);
    scanf("%hu %hu", &N, &M);
    for(uint16_t i = 0; i < M; ++i){
        scanf("%hu %hu", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }   
    for(uint16_t i = 1; i <= N; ++i){
        bfs(i);
        for(uint16_t j = 1; j <= N; ++j){
            seen[j] = false;
        }
        maxdist = 0;
    }
    printf("%hu\n", minmaxdist);
    return 0;
}