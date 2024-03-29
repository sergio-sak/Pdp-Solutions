#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, M;
const int MAXN = 1e5+5;
vi types(MAXN), graph[MAXN], agrotes, moves;
std::vector<bool> vis(MAXN, false), lucky(MAXN, false);

void diefes(int x){
    if(lucky[x]){
        for(auto v : moves){
            lucky[v] = true;
        }
        moves.clear();
    }
    if(vis[x]) return;
    moves.push_back(x);
    vis[x] = true;
    if(types[x] == 1){
        for(auto v : moves){
            lucky[v] = true;
        }
        moves.clear();
        return;
    }
    for(auto v : graph[x]){
        diefes(v);
    }
}

int main()
{
    #ifdef CONTEST
        freopen("shades.in", "r", stdin);
        freopen("shades.out", "w", stdout);
    #else
        freopen("shades.in1", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i){
        scanf("%d", &types[i]);
        if(types[i] == 0)
            agrotes.push_back(i);
    }

    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d\n", &a, &b);
        graph[a].push_back(b);
    }

    for(auto x : agrotes){
        if(!vis[x])
            diefes(x);
    }

    for(int i = 1; i <= N; ++i){
        if(i != N)
            printf("%d ", (int)lucky[i]);
        else
            printf("%d\n", (int)lucky[i]);
    }
    return 0;
}