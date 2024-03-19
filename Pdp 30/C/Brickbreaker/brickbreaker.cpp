#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, M, Q;
std::vector<bool> bricks((size_t)(1e3+3));
std::vector<pi> queries((size_t)(1e3+3));
vi connection((size_t)(1e3+3)), rank((size_t)(1e3 + 3));

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
    if(rank[a] == rank[b])
        rank[a]++;
    if(rank[a] > rank[b])
        connection[b] = a;
    else
        connection[a] = b;
}

void init(int N){
    for(int i = 0; i < N; ++i){
        connection[i] = i;
        rank[i] = 0;
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
   
    for(int i = 0; i < N*M; ++i){
            char chr;
            scanf("%c ", &chr);
            if(chr == '#') bricks[i] = true;
    }
   
    scanf("%d\n", &Q);
    for(int i = 0; i < Q; ++i){
        int x, y;             
        scanf("%d %d\n", &x, &y);
        bricks[convert(x, y)] = false;                                                                              
        queries[i] = {x, y};
    }
    
    return 0;
}

// for(auto out : bricks) {
//         for(auto in : out) {
//             std::cout<<in<<" ";
//         }
//         std::cout<<"\n";
//     }
