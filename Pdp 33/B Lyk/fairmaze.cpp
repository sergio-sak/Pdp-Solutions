#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, M, count;
std::vector<std::vector<char>> maze, path;
std::vector<std::vector<bool>> visited;
std::vector<pi> moves;

void dfs(int y, int x) {
    // for(auto outer : path) {
    //     for(auto inner : outer) {
    //         printf("%c", inner);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    while(true) {
        visited[y][x] = true;
        moves.push_back({y, x});

        if(maze[y][x] == 'U') y--;
        else if(maze[y][x] == 'D') y++;
        else if(maze[y][x] == 'L') x--;
        else if(maze[y][x] == 'R') x++;

        if(y < 0 || y >= N || x < 0 || x >= M) {
            for(auto p : moves) {
                path[p.first][p.second] = 'O';
            }
            moves.clear();
            return;
        }

        if(visited[y][x]) {
            if(path[y][x] == 'O') {
                for(auto p : moves) {
                    path[p.first][p.second] = 'O';
                }
                moves.clear();
                return;
            }
            for(auto p : moves) {
                path[p.first][p.second] = 'I';
            }
            count++;
            moves.clear();
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
    path.resize(N, std::vector<char>(M, 'N'));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &maze[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dfs(i, j);
        }
    }
    printf("%d\n", count);
    return 0;
}
