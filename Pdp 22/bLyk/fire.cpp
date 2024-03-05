#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, M;
std::vector<std::vector<char>> grid;
std::pair<ll, ll> location;

int main()
{
    #ifdef CONTEST
        freopen("fire.in", "r", stdin);
        freopen("fire.out", "w", stdout);
    #else
        freopen("fire.in2", "r", stdin);
    #endif
    
    scanf("%lld %lld", &N, &M);
    scanf("%lld %lld", &location.first, &location.second);

    grid.resize(N+3, std::vector<char>(M+3));

    for(int i = 0; i <= N + 1; ++i){
            grid[i][0] = '@';
            grid[i][N+1] = '@';
        for(int j = 0; j <= M+1; ++j){
            scanf("%c", &grid[i][j]);
        }
    } 

    for(auto outer : grid){
        for(auto inner : outer){
            printf("%c", inner);
        }
        printf("\n");
    }
    return 0;
}