#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, M, count;
std::vector<std::vector<char>> maze;
std::vector<std::vector<bool>> visited;

void dfs(int x, int y) {
    std::stack<pi> s;
    s.push(std::make_pair(x, y));
    while(!s.empty()) {
        pi u = s.top(); s.pop();
        visited[u.first][u.second] = true;
        
        if(maze[u.first][u.second] == 'U') {
            u.first++;
            s.push(std::make_pair(u.first, u.second));
        }
        else if(maze[u.first][u.second] == 'D') {
            u.first--;
            s.push(std::make_pair(u.first, u.second));
        }
        else if(maze[u.first][u.second] == 'L') {
            u.second--;
            s.push(std::make_pair(u.first, u.second));
        }
        else if(maze[u.first][u.second] == 'R') {
            u.second++;
            s.push(std::make_pair(u.first, u.second));
        }
        if(u.first < 0 || u.first >= N || u.second < 0 || u.second >= M) {
            return;
        }
        if(visited[u.first][u.second]) {
            count++;
            return;
        }
    }
}

int main()
{
    #ifdef CONTEST
        freopen("fairmaze.in", "r", stdin);
        freopen("fairmaze.out", "w", stdout);
    #else
        freopen("fairmaze.in", "r", stdin);
    #endif
    scanf("%d %d", &N, &M);
    maze.resize(N, std::vector<char>(M));
    visited.resize(N, std::vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &maze[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dfs(i, j);
            for(int k = 0; k < N; k++) {
                for(int l = 0; l < M; l++) {
                    visited[k][l] = false;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
