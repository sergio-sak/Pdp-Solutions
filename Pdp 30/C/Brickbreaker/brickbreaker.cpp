#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, M, Q;
std::vector<std::vector<bool>> bricks;
vi connection((size_t)(1e3+3)), size((size_t)(1e3 + 3));

int convert(int i, int j){
    return i * M + j;
}

//UNION FIND

int find(int x){
    while(x != connection[x]) x = connection[x];
    return x;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) std::swap(a, b);
    size[a] += size[b];
    connection[b] = a;
}

void init(int N){
    for(int i = 0; i < N; ++i){
        connection[i] = i;
        size[i] = 1;
    }
}

//END UNION FIND


int main()
{
    #ifdef CONTEST
        freopen("brickbreaker.in", "r", stdin);
        freopen("brickbreaker.out", "w", stdout);
    #else
        freopen("brickbreaker.in", "r", stdin);
    #endif
   
    scanf("%d %d\n", &N, &M);
    bricks.resize(N, std::vector<bool>(M, false));
   
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j) {

            char chr;
            scanf("%c ", &chr);
            if(chr == '#') bricks[i][j] = true;
        }
    }
   
    return 0;
}

// for(auto out : bricks) {
//         for(auto in : out) {
//             std::cout<<in<<" ";
//         }
//         std::cout<<"\n";
//     }
