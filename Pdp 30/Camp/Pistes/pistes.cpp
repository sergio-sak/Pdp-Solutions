#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, K, R, S, start_S, temp, max_stars = 0, cur_stars = 0;
vll cur, cur_perm, chosen;
std::vector<vll> rest;
std::unordered_map<ll, ll> keys;

void search(){
    if(cur_perm.size() == N){
        std::unordered_map<ll, ll> keys_copy = keys;
        cur_stars = start_S;
        for(auto indx : cur_perm){
            K = rest[indx][0];
            R = rest[indx][1];
            S = rest[indx][2];
            for(int i = 3; i < 3+K; ++i){
                keys_copy[rest[indx][i]]--;
                if(keys_copy[rest[indx][i]] < 0){
                    max_stars = std::max(max_stars, cur_stars);
                    cur_stars = start_S;
                    return;
                }
            }
            for(int i = 3+K; i < 3+K+R; ++i){
                keys_copy[rest[indx][i]]++;
            }
            cur_stars += S;
        }
            keys = keys_copy;
            max_stars = std::max(max_stars, cur_stars);
        //cur_stars = start_S;
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
        freopen("Testcases/pistes.in13", "r", stdin);
    #endif
   
    scanf("%lld", &N);
    rest.push_back({});
    chosen.resize(N+1);

    scanf("%lld %lld %lld", &K, &R, &S);
    for(int i = 0; i < R; ++i){
        scanf("%lld", &temp);
        keys[temp]++;
    }
   
    //std::cout<<K<<" "<<R<<" "<<S<<" "<<temp<<"\n";
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
    printf("%lld\n", max_stars);
    return 0;
}
