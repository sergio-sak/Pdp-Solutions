#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, K, temp, left = 0, right = 0, complement, res = 0;
vll chemicals;
std::unordered_map<ll, vll> hmap;

int main()
{
    #ifdef CONTEST
        freopen("chemicals.in", "r", stdin);
        freopen("chemicals.out", "w", stdout);
    #else
        freopen("testcases/chemicals.in2", "r", stdin);
    #endif

    scanf("%lld %lld", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%lld", &temp);
        chemicals.push_back(temp%K);
        hmap[chemicals[i]].push_back(i);
    }

    while(left<=right && right < N) {
        complement = K - chemicals[right];
        if(hmap.count(complement)){
            int i = 0;
            while(hmap[complement][i] == -1 && i < hmap[complement].size()){
                i++;
            }
            if(hmap[complement][i]>right) right++;
            else {
                int i = 0;
                hmap[complement][i] = -1;
                left++;
            }
        }
        else {
            right++;
        }
        std::cout << left << " " << right << std::endl;
        res = std::max(res, right-left+1);
    }
    printf("%lld\n", res);
    return 0;
}