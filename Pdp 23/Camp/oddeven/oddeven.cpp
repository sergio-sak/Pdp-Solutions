#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, temp, count = 0, res = 0;
vll oddeven;
std::unordered_map<ll, pl> hmap;

int main()
{
    #ifdef CONTEST
        freopen("oddeven.in", "r", stdin);
        freopen("oddeven.out", "w", stdout);
    #else
        freopen("testcases/oddeven/oddeven.in4", "r", stdin);
    #endif

    scanf("%lld", &N);

    oddeven.push_back(0);

    for(int i = 0; i < N; ++i) {
        scanf("%lld", &temp);
        (temp % 2 == 0) ? oddeven.push_back(--count) : oddeven.push_back(++count);
        if(hmap.count(oddeven[i])) hmap[oddeven[i]].second = i;
        else hmap[oddeven[i]].first = i;
    }

    for(int i = 0; i < N; ++i){
        res = std::max(res, hmap[oddeven[i]].second - hmap[oddeven[i]].first);
    }
    printf("%lld\n", res);
    return 0;
}