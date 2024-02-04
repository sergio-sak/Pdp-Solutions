#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

int N, K, R, S, start_S, temp;
int max_stars = 0, cur_stars = 0;
std::vector<int> perm, cur;
std::vector<std::vector<int>> rest;
std::map<int, int> keys;
bool flag = true;

int main()
{
    #ifdef CONTEST
        freopen("pistes.in", "r", stdin);
        freopen("pistes.out", "w", stdout);
    #else
        freopen("Testcases/pistes.in8", "r", stdin);
    #endif
   
    scanf("%d", &N);
    rest.push_back({});
    scanf("%d %d %d", &K, &R, &S);
    for(int i = 0; i < R; ++i){
        scanf("%d", &temp);
        keys[temp]++;
    }
   
    cur_stars = S;
    start_S = S;
   
    for(int i = 1; i <= N; ++i){
        scanf("%d %d %d", &K, &R, &S);
        cur.push_back(K);
        cur.push_back(R);
        cur.push_back(S);
        for(int j = 0; j < K; ++j){
            scanf("%d", &temp);
            cur.push_back(temp);
        }
        for(int j = 0; j < R; ++j){
            scanf("%d", &temp);
            cur.push_back(temp);
        }
        rest.push_back(cur);
        cur.clear();
    }

    for(int i = 1; i <= N; ++i){
        perm.push_back(i);
    }
    do {
        cur_stars = start_S;
        flag = true;
        std::map<int, int> keys_copy = keys;
        for(int j = 0; j < N; ++j){
            K = rest[perm[j]][0];
            R = rest[perm[j]][1];
            S = rest[perm[j]][2];
            for(int i = 3; i < 3 + K; ++i){
                keys_copy[rest[perm[j]][i]]--;
                if(keys_copy[rest[perm[j]][i]] < 0){
                    cur_stars = start_S;
                    max_stars = std::max(max_stars, cur_stars);
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            for(int i = 3 + K; i < 3 + K + R; ++i){
                keys_copy[rest[perm[j]][i]]++;
            }
            cur_stars += S;
            max_stars = std::max(max_stars, cur_stars);
        }
    }while(std::next_permutation(perm.begin(), perm.end()));

    printf("%d\n", max_stars);
    return 0;
}
