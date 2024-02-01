#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, K, R, S, start_S, temp, max_stars = 0, cur_stars = 0;
vll cur, cur_perm, chosen;
std::vector<vll> rest, perms;
std::unordered_map<ll, ll> keys;
bool end = false;

void search(){
    if(cur_perm.size() == N){
        perms.push_back(cur_perm);
    }
    else {
        for (int i = 1; i <= N; ++i){
            if(chosen[i]) continue;
            chosen[i] = true;
            cur_perm.push_back(i);
            search();
            chosen[i] = false;
            cur_perm.pop_back(); 
        }
    }
}

int main()
{
    #ifdef CONTEST
        freopen("pistes.in", "r", stdin);
        freopen("pistes.out", "w", stdout);
    #else
        freopen("pistes.in1", "r", stdin);
    #endif
    
    scanf("%lld", &N);
    rest.push_back({});
    chosen.resize(N+1);

    scanf("%lld %lld %lld", &K, &R, &S);
    for(int i = 0; i < R; ++i){
        scanf("%lld", &temp);
        keys[temp]++;
    }
    cur_stars = S;
    start_S = S;
    for(int i = 1; i <= N; ++i){
        scanf("%lld %lld %lld", &K, &R, &S);
        cur.push_back(K);
        cur.push_back(R);
        cur.push_back(S);
        for(int j = 0; j < K; ++j){
            scanf("%lld", &temp);
            cur.push_back(temp);
        }
        for(int j = 0; j < R; ++j){
            scanf("%lld", &temp);
            cur.push_back(temp);
        }
        rest.push_back(cur);
        cur.clear();
    }
    search();
    
    for(auto perm : perms){
        std::unordered_map<ll, ll> keys_copy = keys;
        for(auto indx : perm){
            K = rest[indx][0];
            R = rest[indx][1];
            S = rest[indx][2];
            for(int i = 3; i < 3+K; ++i){
                keys_copy[rest[indx][i]]--;
                if(keys_copy[rest[indx][i]] < 0){
                    cur_stars = start_S;
                    end = true;
                    break;
                }
            }
            if(end){
                end = false;
                break;
            }
            for(int i = 3+K; i < 3+K+R; ++i){
                keys_copy[rest[indx][i]]++;
            }
            cur_stars += S;
            keys=keys_copy;
        }
        max_stars = std::max(max_stars, cur_stars);
        cur_stars = start_S;
    }
    
    printf("%lld\n", max_stars);
    return 0;
}
